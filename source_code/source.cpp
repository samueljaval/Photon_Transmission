#include "source.hpp"


void Source::printVec(vector<float> input)
{
    for (int i = 0; i < input.size(); i++)
    {
		cout << input.at(i) << ' ' << endl;
	}
}

void Source::ParseSource(ifstream& ifs)
{

    string  thing;
   // ifs.seekg(0, ios::beg);     //have to reset the stream
    int nb_things = 0;
    ifs >> thing;
    nb_things = stoi(thing);
    for (int i = 0; i < nb_things; i++)
    {
        ifs >> thing;
        Energy.push_back(stof(thing));
        ifs >> thing;
        Intensity.push_back(stof(thing));
    }
}

float Source::pickEnergy()
{
    Itot = 0.;
    for (int i = 0; i < Intensity.size(); i++)
    {
        Itot += Intensity[i];
    }
    double randomNum = rando->GetAlea();
    float sum_intensities = 0;
    for (int i=0; i<Energy.size(); i++)
    {
        sum_intensities += Intensity[i];
        if (randomNum < (double) sum_intensities/Itot)   // (double) is for conversion to double
        {
            //cout << "Energy was picked!" << endl;
            return Energy[i];
        }
    }
    cout << "ERROR : No energy was picked";
    return 0;
}

Photon * Source::MakePhoton()
{
    E = pickEnergy();
    //cout << "the picked energy is " << E << endl;
    photon = new Photon(E);
    return photon;
}

