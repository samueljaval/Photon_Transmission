/******************************************************************************
/ Photon Transport through a projected straight ahead Monte-Carlo Simulation
/ July 2019
*******************************************************************************/


#include <iostream>
#include <string>
#include "dataModel.hpp"
#include "transport.hpp"
#include "Aleatoire.hpp"
#include <fstream>

using namespace std;

long long seed = -3;
LECUYER* rando = new LECUYER(seed);
int photon_number;

int main(int argc, char *argv[])
{
    Transport* transport;
    dataModel* datamodel;
    ofstream log;
    log.open("photons.log", ofstream::out | ofstream::trunc);
    log.close();
    ofstream log2;
    log2.open("hotside.log", ofstream::out | ofstream::trunc);
    log2.close();
    ofstream log3;
    log3.open("coldside.log", ofstream::out | ofstream::trunc);
    log3.close();
    ofstream log4;
    log.open("doserate.log", ofstream::out | ofstream::trunc);
    log.close();
    ofstream log5;
    log5.open("stat_collision.log", ofstream::out | ofstream::trunc);
    log5.close();

    if (argc == 2)
    {

        Photon * photon;
        string inputFile = argv[1];
        datamodel = new dataModel(inputFile);
        transport = new Transport(datamodel);
        cout << "START" << endl;
        for (int i = 1; i < photon_number; i++)  //loop over 100 photons
        {
            if ( i % 100000 == 0 )
            {
                double percent = (double)i / photon_number;
                percent *= 100;
                cout << percent << " %" << endl;
            }
            photon = datamodel->GiveMePhoton();
            photon->number = i;
            transport->linearTransport(photon);
            if (photon) delete photon;
        }
        datamodel->hotside->showBins("hotside.log");
        datamodel->coldside->showBins("coldside.log");
        datamodel->FindAttenuation();
        datamodel->doserate->show("doserate.log");
        transport->Spool("stat_collision.log");
        if (transport != NULL) delete transport;
        if (datamodel != NULL) delete datamodel;
    }
    delete rando;

    return 0;
}
