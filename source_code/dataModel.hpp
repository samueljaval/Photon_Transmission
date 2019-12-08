#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <iostream>
#include "source.hpp"
#include "tally.hpp"
#include "medium.hpp"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
extern int photon_number;

class dataModel {

public :
    dataModel(string);
    ~dataModel();

    Medium* medium;
    Source* source;
    Tally* tally;
    Photon * GiveMePhoton();
    Spectrum* hotside;
    Spectrum* coldside;
    DoseRate* doserate;
    void FindAttenuation();



private :
    ifstream ifs;
    int readFile();

};

#endif
