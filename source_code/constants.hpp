#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <sstream>  /// for ostringstream
#include <fstream>
#include <string>

using namespace std;

/* const int photon_number = 10000000;*/
const float EMIN = 0.01;
const float EMAX = 10.0;
enum INTERACTION {NONE=0, ABSORPTION_PE=1, INC_SCATTERING_CE=2, ABSORPTION_PP=3};
const float TOLmass = 0.01;             /// 1% tolerance
const bool TRACE = false;


template <class T>
string Write_d(T var, int Width, int precision = 3)
{
	ostringstream sortie;
	sortie.width(Width);
	sortie.fill(' ');

	sortie << scientific;
    sortie.precision(precision);

	sortie << var << "";
	return sortie.str().c_str();
}


class Function
{

    private:
      int NbPoints;
      double * ABS;
      double * ORD;

    public:
      Function(int dim, ifstream& entree)
      {
        NbPoints = dim;
        ABS = new double[NbPoints];
        ORD = new double[NbPoints];
        string thing;
        for (int i = 0; i<NbPoints; i++)
        {
            entree >> thing;
            ABS[i] = stod(thing);
            entree >> thing;
            ORD[i] = stod(thing);
        }
      }
     ~Function() { if (ABS) delete[] ABS; if (ORD) delete[] ORD; }

      double Interpole(const double & abscisse)
      {
        if( abscisse<ABS[0] || abscisse>ABS[NbPoints-1] ){
        return 0.;
        }

        int i=1,indice=0;
        while ( i < NbPoints )
        {
          if ( abscisse <= ABS[i] ) { indice = i; break; }
          i++;
        }
        double interp = (ORD[indice]-ORD[indice-1])/(ABS[indice]-ABS[indice-1]); /// à REMPLACER par du LOG-LOG
        interp *= (abscisse - ABS[indice-1]);
        interp += ORD[indice-1];
        return interp;
      }
};

#endif  // CONSTANTS
