#ifndef TALLY_H
#define TALLY_H

#include "constants.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include "photon.hpp"

using namespace std;
extern int photon_number;

class Tally
{

    public :
    Tally(){sum_transmit = 0.;}
    ~Tally(){}

    virtual void ParseTally(ifstream&);
    virtual void Score(Photon*) = 0;
    virtual void showBins(string);

    vector<string> bins;
    vector<float> stackingBins;
    void Write(ofstream&);
    double sum_transmit;

    protected :
    void stackEnergy(Photon *);
    string fileName;
    template<class T> void printVec(vector<T>);

    private:
    void GetBins();

};

class Spectrum : public Tally
{
    public:
    Spectrum(){}
    ~Spectrum(){}

    /*virtual*/ void Score(Photon * p) { stackEnergy(p); }
    /*virtual*/ void showBins(string s){ Tally::showBins(s); }

    private :
    ///virtual void fromTally(ifstream&);
};

class DoseRate : public Tally
{
    public :
    DoseRate();
    ~DoseRate(){if (DRcurve) delete DRcurve;}
    /*virtual*/ void Score(Photon*);
    /*virtual*/ void ParseTally(ifstream&);
    void readFile(string);
    void show(string);
    Function * DRcurve;
    double doserate_scalar;

    void SetAttenuation(double a) { A_coeff = a; }
    void SetUncertainty(double a) { A_uncertainty = a; }

    private:
    string     DRname;
    string     DRunit;
    string     DRreference;
    string     DRgroup;
    double A_coeff;     /// coefficient d'attenuation
    double A_uncertainty;
};

#endif
