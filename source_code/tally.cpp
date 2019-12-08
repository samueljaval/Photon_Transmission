#include "tally.hpp"


void Tally::ParseTally(ifstream& ifs) {

    string  thing;
    ifs >> thing;
    istringstream iss(thing);
    iss >> fileName;
    GetBins();
}

template <class T>
void Tally::printVec(vector<T> input)
{
    for (int i = 0; i < input.size(); i++)
    {
		cout << input[i] << ' ' << endl;
	}
}

void Tally::GetBins() {

    ifstream ifs;
    ifs.open(fileName);
    string thing;
    ifs >> thing;
    ifs >> thing;
    while ( ! ifs.eof() ) {
        ifs >> thing;
        if ( stof(thing) >= 1000.0*EMIN && stof(thing) <= 1000.0*EMAX)
        {
            bins.push_back(thing); /// keV <--> MeV
            stackingBins.push_back(0.);
        }
    }

}


void Tally::stackEnergy(Photon * p)
{
    if (bins.empty()) cout << "BINS ARE EMPTY" << endl;
    for (int i = 0; i < bins.size(); i++)
    {
        if ( p->E <= stof(bins[i]) / 1000 )
        {
            stackingBins[i] += p->weight;
            sum_transmit += p->weight;
            break;
        }
    }
}

void Tally::showBins(string name)
{
    ofstream ofstr;
    ofstr.open(name, ios::app);
    Write(ofstr);
    ofstr<< "total number of received photons  =  " <<sum_transmit<<endl;
    ofstr.close();
}

void Tally::Write(ofstream& of)
{
    int sum = 0;
    int i = 0;
    for (const float& e : stackingBins)
    {
        float p = e/photon_number;
        float uncertainty = sqrt((1-p)/(p*photon_number));
        if (uncertainty > photon_number) uncertainty = 0;
        if (i == 0) of << e << "                    at energy less than " << stof(bins[i])/1000 << " MeV            uncertainty = " << uncertainty << endl;
        else of << e << "                    at energy between " << stof(bins[i-1])/1000 << " and " <<stof(bins[i])/1000<< " MeV            uncertainty = " << uncertainty << endl;
        i++;
    }
}


DoseRate::DoseRate()
{
    doserate_scalar = 0.;
    A_coeff = 0.;
}

void DoseRate::Score(Photon * p)
{
    doserate_scalar += p->weight * DRcurve->Interpole((p->E)*1000)/photon_number;     // MeV<-->keVs
}

void DoseRate::ParseTally(ifstream& ifs)
{
    string thing;
    ifs >> fileName;
    readFile(fileName);
}

void DoseRate::readFile(string s)
{
    ifstream ifs;
    ifs.open(s);
    string thing;
    ifs >> thing;
    if ( "Name" == thing )
    {
      ifs >> DRname;
      ifs >> thing;
      if( "Unit" == thing )
      {
        ifs >> DRunit;
        ifs >> thing;
        if( "Ref" == thing )
        {
          ifs >> DRreference;
          ifs >> thing;
          if( "Def" == thing )
          {
            ifs >> DRgroup;
            DRcurve = new Function(stoi(DRgroup), ifs);
          }
          else { cout << endl <<"Def keyword absent. Please verify."<<endl; }
        }
        else { cout << endl <<"Ref keyword absent. Please verify."<<endl; }
      }
      else { cout << endl <<"Unit keyword absent. Please verify."<<endl; }
    }
    else { cout << endl <<"Name keyword absent. Please verify."<<endl; }
}

void DoseRate::show(string name)
{
    ofstream ofstr;
    ofstr.open(name, ios::app);
    ofstr << doserate_scalar << " is the dose rate scalar" << endl;
    ofstr << A_coeff << " is attenuation coefficient with uncertainty  :   " << A_uncertainty << endl;
    ofstr.close();
}





