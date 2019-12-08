#ifndef SOURCE_H
#define SOURCE_H

#include "Aleatoire.hpp"
#include "photon.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

extern LECUYER* rando;

class Source {

    public:

        Source(){}
        ~Source(){}
        void ParseSource(ifstream&);
        Photon * MakePhoton();
        float pickEnergy();
        float GetTotalIntensity() { return Itot; }

        vector<float> Energy;
        vector<float> Intensity;

        float E;


    private :

        void printVec(vector<float>);
        Photon* photon;
        float Itot;
};


#endif
