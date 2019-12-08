#ifndef COLLISION_H
#define COLLISION_H
#include "medium.hpp"
#include "Aleatoire.hpp"
#include "transport.hpp"
#include <math.h>

extern LECUYER* rando;

class Collision
{

    public:
    Collision(){}
     ~Collision(){}

    virtual void DoCollision(Photon*) = 0;
    Photon* photon;

    protected :
    double PI = 3.1415926535897932384626433832795028841971;

};


//-------------------type of collision-----------------------//


class PE : public Collision     //Photoelectric effect
{
    public :
    PE(){}
    ~PE();

    /*virtual*/ void DoCollision(Photon*);
};

class CE : public Collision     //Compton effect
{
    public :
    CE(){}
    ~CE(){}

    /*virtual*/ void DoCollision(Photon*);

    protected :
    double CosDev;
};

class PP : public Collision     //Pair production
{
    public :
    PP(){}
    ~PP(){}

    /*virtual*/ void DoCollision(Photon*);

};



#endif
