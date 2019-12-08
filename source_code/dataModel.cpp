#include "dataModel.hpp"

dataModel::dataModel(string name) {

    ifs.open(name.c_str());
    readFile();
}

dataModel::~dataModel() {
    if (source != NULL) delete source;
    if (medium != NULL) delete medium;
    if (tally  != NULL) delete tally;
    if (hotside != NULL) delete hotside;
    if (coldside != NULL) delete coldside;

}

int dataModel::readFile() {

    string  Line, thing;

    while (!ifs.eof()) {

        ifs >> thing;
        if ( !thing.compare("PHOTON_NUMBER") )
        {
            ifs >> thing;
            photon_number = stoi(thing);
        }
        if ( !thing.compare("SOURCE") ) {
            source = new Source();
            source->ParseSource(ifs);
        }
        else if ( !thing.compare("MEDIUM") ) {
            medium = new Medium();
            medium->ParseMedium(ifs);
        }
        else if ( !thing.compare("TALLY") ) {

            ifs >> thing;
            int max = stoi(thing);
            for (int t = 0; t < max; t++)
            {
                ifs >> thing;
                if ( !thing.compare("BACKSCATTERED") )
                {
                    hotside = new Spectrum();
                    hotside->ParseTally(ifs);
                }
                if ( !thing.compare("TRANSMITTED") )
                {
                    coldside = new Spectrum();
                    coldside->ParseTally(ifs);
                }
                if ( !thing.compare("DOSERATE") )
                {
                    doserate = new DoseRate();
                    doserate->ParseTally(ifs);
                }
            }
        }
    }

    return 0;

}

void dataModel::FindAttenuation()
{
    double DR = doserate->doserate_scalar;
    double Sum = 0;
    /*vector<float> E_vector;
    vector <float> I_vector;
    for (int i ; i< source->Energy.size(); i++) {E_vector.push_back(source->Energy[i]);}
    for (int i ; i< source->Intensity.size(); i++) {I_vector.push_back(source->Intensity[i]);}*/
    double D;

    for (int i = 0; i < source->Energy.size(); i++)
    {
        D = 1000.*source->Energy[i];
        Sum += doserate->DRcurve->Interpole(D) * source->Intensity[i];
    }
    DR *= source->GetTotalIntensity();
    double sum = coldside->sum_transmit;
    double p = sum / photon_number;
    double Uncertainty = sqrt((1 - p)/(p * photon_number));
    doserate->SetAttenuation(DR / Sum);
    doserate->SetUncertainty(Uncertainty);
}


Photon * dataModel::GiveMePhoton()
{
    return source->MakePhoton();
}
