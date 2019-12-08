#include "medium.hpp"

using namespace std;



XSpoint& XSpoint::operator+=(const XSpoint& rhs)
{
    IncScat += rhs.IncScat;
    PEabs   += rhs.PEabs;
    NuclPP  += rhs.NuclPP;
    ElecPP  += rhs.ElecPP;
    TotPP   += rhs.TotPP;
    Tot     += rhs.Tot;

    return *this;
}


XSpoint& XSpoint::operator*=(float rhs)
{
    this->IncScat *= rhs;
    this->PEabs   *= rhs;
    this->NuclPP  *= rhs;
    this->ElecPP  *= rhs;
    this->TotPP   *= rhs;
    this->Tot     *= rhs;

    return *this;
}


void Medium::ParseMedium(ifstream& ifs)
{
    string  Line, thing;
    ifs >> thing;
    nb_elements = stoi(thing);
    ifs >> thing;
    thickness = stof(thing);
    ifs >> thing;
    density = stof(thing);
    for (int i = 0; i < nb_elements; i++)
    {
        ifs >> thing;
        Z.push_back(thing);
        ifs >> thing;
        weightFraction.push_back(stof(thing));
    }
    ValorizeXS();
}


void Medium::ValorizeXS()
{
    for (int z = 0; z < nb_elements; z++)
    {
        ifstream ifstr;
        Compound compound;
        ifstr.open("xsdir_xcom/Z"+Z[z]+".xs",ios::in);
        string Line, thing;

        while ( !ifstr.eof() )
        {
            getline(ifstr, Line);           /// to skip the first line (#Zzz.xs)
            XSpoint xspoint;
            ifstr >> thing;
            if ( thing.compare("#Photon") && thing.compare("#Energy") )
            {
                if ( stof(thing) >= EMIN && stof(thing) <= EMAX )  /// skip cross sections < EMIN and > EMAX
                {
                    xspoint.En = stof(thing);

                    /// get the cross section in the XCOM file and weight it with its mass fraction
                    ifstr >> thing;         /// pass the coherent scattering
                    ifstr >> thing;
                    xspoint.IncScat = stof(thing)*weightFraction[z];

                    ifstr >> thing;
                    xspoint.PEabs = stof(thing)*weightFraction[z];

                    ifstr >> thing;
                    xspoint.NuclPP = stof(thing)*weightFraction[z];

                    ifstr >> thing;
                    xspoint.ElecPP = stof(thing)*weightFraction[z];

                    xspoint.TotPP = xspoint.NuclPP + xspoint.ElecPP;

                    ifstr >> thing;         /// pass the total "with coherent" XS
                    ifstr >> thing;
                    xspoint.Tot = stof(thing)*weightFraction[z];

                    compound.pointwiseXS.push_back(xspoint);
                }
            }
        }   /// end of XCOM file reading for one material
        compound.Z = stoi(Z[z]);
        composition.push_back(compound);
    }
/*
    /// serializing
    for (int z = 0; z < nb_elements; z++)
    {
        cout << Z[z] << endl;
        for (int e = 0; e < composition[z].pointwiseXS.size(); e++)
        {
            cout << Write_d(composition[z].pointwiseXS[e].En,11) << Write_d(composition[z].pointwiseXS[e].IncScat,12)
                 << Write_d(composition[z].pointwiseXS[e].PEabs,12)
                 << Write_d(composition[z].pointwiseXS[e].TotPP,12) << Write_d(composition[z].pointwiseXS[e].Tot,12) << endl;
        }
        cout << endl << endl;
    }*/
}


float Medium::GetLinearAttenuation(float E)
{
    if ( E < EMIN || E > EMAX ) return -1.;     /// to detect an out of range, just test a positive return

    XSpoint cumulateXS = GetXS(E);

    return ( cumulateXS.IncScat + cumulateXS.PEabs + cumulateXS.TotPP );
}


INTERACTION Medium::GetInteraction(float E, float xsi)
{
    if ( E < EMIN || E > EMAX ) return NONE;    /// to detect an out of range, just test a NONE return

    INTERACTION interaction = NONE;

    XSpoint cumulateXS = GetXS(E);

    float xsTot = cumulateXS.IncScat + cumulateXS.PEabs + cumulateXS.TotPP;

    if      ( xsi < cumulateXS.PEabs/xsTot )                      interaction = ABSORPTION_PE;
    else if ( xsi < (cumulateXS.PEabs+cumulateXS.IncScat)/xsTot ) interaction = INC_SCATTERING_CE;
    else                                                          interaction = ABSORPTION_PP;

    /// serializing
    /*
    cout << Write_d(cumulateXS.En,11) << Write_d(cumulateXS.IncScat,12)
         << Write_d(cumulateXS.PEabs,12) << Write_d(cumulateXS.TotPP,12) << Write_d(cumulateXS.Tot,12) << endl;
    */
    return interaction;
}


void Compound::Sort()
{
    sort(pointwiseXS.begin(), pointwiseXS.end());
}


bool XSpoint::operator<(const XSpoint &a)
{
    return En < a.En;
}


XSpoint Medium::GetXS(float E)
{
    XSpoint cumulateXS;
    cumulateXS.En = E;

    for (int z = 0; z < nb_elements; z++)
    {
        for (int e = 0; e < composition[z].pointwiseXS.size(); e++)
        {
            if ( E == composition[z].pointwiseXS[e].En )         /// match a given XS
            {
                cumulateXS += composition[z].pointwiseXS[e];
                break;
            }
            if ( E < composition[z].pointwiseXS[e].En )         /// need be interpolated
            {
                cumulateXS += XS_at_E(E,e,composition[z].pointwiseXS);
                break;
            }
        }
    }
    cumulateXS *= density;      /// to have /cm XS

    return cumulateXS;
}


XSpoint Medium::XS_at_E(float E, int e, const vector<XSpoint>& xs)  /// ugly method : change when possible
{
    XSpoint point;

    point.PEabs   = exp( log(xs[e].PEabs/xs[e-1].PEabs) / log(xs[e].En/xs[e-1].En) * log(E/xs[e-1].En) + log(xs[e-1].PEabs) );

    point.IncScat = exp( log(xs[e].IncScat/xs[e-1].IncScat) / log(xs[e].En/xs[e-1].En) * log(E/xs[e-1].En) + log(xs[e-1].IncScat) );

    if ( xs[e].NuclPP != 0 && xs[e-1].NuclPP != 0 )
        point.NuclPP  = exp( log(xs[e].NuclPP/xs[e-1].NuclPP) / log(xs[e].En/xs[e-1].En) * log(E/xs[e-1].En) + log(xs[e-1].NuclPP) );
    else if ( xs[e].NuclPP != 0 && xs[e-1].NuclPP == 0 )
        point.NuclPP  = xs[e].NuclPP / (xs[e].En - xs[e-1].En) * (E - xs[e-1].En);  /// xs[e-1].NuclPP == 0
    else point.NuclPP = 0;

    if ( xs[e].ElecPP != 0 && xs[e-1].ElecPP != 0 )
        point.ElecPP  = exp( log(xs[e].ElecPP/xs[e-1].ElecPP) / log(xs[e].En/xs[e-1].En) * log(E/xs[e-1].En) + log(xs[e-1].ElecPP) );
    else if ( xs[e].ElecPP != 0 && xs[e-1].ElecPP == 0 )
        point.ElecPP  = xs[e].ElecPP / (xs[e].En - xs[e-1].En) * (E - xs[e-1].En);  /// xs[e-1].ElecPP == 0
    else point.ElecPP = 0;

    point.TotPP   = point.NuclPP + point.ElecPP;

    point.Tot     = exp( log(xs[e].Tot/xs[e-1].Tot) / log(xs[e].En/xs[e-1].En) * log(E/xs[e-1].En) + log(xs[e-1].Tot) );

    return point;
}


template <class T>
void Medium::printVec(vector<T> input)
{
    for (int i = 0; i < input.size(); i++)
    {
		cout << input[i] << ' ' << endl;
	}
}
