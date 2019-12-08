#ifndef TRANSPORT_H
#define TRANSPORT_H
#include "photon.hpp"
#include "collision.hpp"
#include "dataModel.hpp"
#include "constants.hpp"
#include <math.h>

extern LECUYER* rando;

class Collision;

class Transport {

    public :
    Transport(dataModel* d){ data = d; number_CE = 0; number_PE = 0; number_PP = 0;}
    ~Transport(){}

    void linearTransport(Photon *);
    Photon* photon;

    void Spool(string);


    private :
    dataModel * data;
    Collision* collision;
    INTERACTION interaction;
    float linAtenuation;
    int number_PP;
    int number_PE;
    int number_CE;


};





#endif
