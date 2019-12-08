#ifndef PHOTON_H
#define PHOTON_H
#include <iostream>
#include <fstream>

using namespace std;

class Photon
{
    public:
    Photon(float);
    ~Photon(){}

    float weight;
    float E;
    double cosTheta;
    float position;
    int number;

    void Spool(ofstream&);
    void FillLogFile();



};





#endif
