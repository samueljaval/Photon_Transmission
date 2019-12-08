#ifndef _ALEATOIRE_H_INCLUDED
#define _ALEATOIRE_H_INCLUDED

#include <iostream>
#include <cmath>
#include <fstream>  // stream


class PseudoRandom
{
public:
  PseudoRandom(long long s);
  ~PseudoRandom() {}

  virtual double GetAlea() = 0;
  virtual void Spool(std::ofstream &) = 0;

protected:
  long long seed;
  long long current;
  double compteur;

  long k;
  double xsi;
};


const long long p = 2147483647;    // p=(2^31)-1
const long long g = 16807;         // g=nb premier
const long long q = 127773;
const long long r = 2836;
const long long MASK = 123459876;  // pour �viter une graine nulle

class LGM : public PseudoRandom
{
public:
  LGM(long long s);
  ~LGM() {}

  /*virtual*/ double GetAlea();
  /*virtual*/ void Spool(std::ofstream &);
};

class LECUYER : public PseudoRandom
{
public:
  LECUYER(long long s);
  ~LECUYER() {}

  /*virtual*/ double GetAlea();
  /*virtual*/ void Spool(std::ofstream &);
};


#endif // _ALEATOIRE_H_INCLUDED
