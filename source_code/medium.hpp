#ifndef MEDIUM_H
#define MEDIUM_H

#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <algorithm>    /// for sort
#include "constants.hpp"

struct XSpoint
{
    XSpoint(float En=0,float IncScat=0,float PEabs=0,float NuclPP=0,float ElecPP=0,float TotPP=0,float Tot=0):
    En(En),IncScat(IncScat),PEabs(PEabs),NuclPP(NuclPP),ElecPP(ElecPP),TotPP(TotPP),Tot(Tot){}
    float En;                   //Energy
    float IncScat;              //Incoherent Scattering
    float PEabs;                //Photoelectric absorption
    float NuclPP;               //Nuclear Pair Production
    float ElecPP;               //Electron Pair Production
    float TotPP;                //Total for Pair production
    float Tot;
    bool operator<(const XSpoint&);
    XSpoint& operator+=(const XSpoint& rhs);
    XSpoint& operator*=(float rhs);
};

class Compound
{
public:
    int Z;
    vector<XSpoint> pointwiseXS;          /// cross sections of the compound

private:
    void Sort();

};


class Medium
{
    public :

        Medium(){}
        ~Medium(){}

        void ParseMedium(ifstream&);
        float GetLinearAttenuation(float);          /// gives the linear attenuation coefficient at energy E
        INTERACTION GetInteraction(float,float);    /// gives the randomly selected interaction at energy E
        float thickness;




    private :

        template<class T> void printVec(vector<T>);      ///just to test if data extraction code works

        XSpoint GetXS(float);
        XSpoint XS_at_E(float, int, const vector<XSpoint>&);    /// interpolate medium XS at energy E

        int nb_elements;
        float density;
        vector<float> weightFraction;
        vector<string> Z;
        vector<Compound> composition;
        vector<float> energyGrid;

        void ValorizeXS();

};

#endif
