#include "Aleatoire.hpp"

using namespace std;

PseudoRandom::PseudoRandom(long long s)
{
    seed = current = s;
    compteur = 0.;
}

LGM::LGM(long long s) : PseudoRandom(s)
{

}

double LGM::GetAlea()
{
  compteur += 1;
/*  ############################################################
    ######   G�n�ration d'un nombre al�atoire (ran0)      ######
    ############################################################
    ######    Algorithme multiplicatif congruentiel de    ######
    ######       Lewis, Goodman et Miller (en 1969)       ######
    ######             I(j+1) = g.I(j) mod p              ######
    ######   avec g=7^5=16807 et p=(2^31)-1=2147483647    ######
    ######     modifi� avec l'algorithme de Schrage :     ######
    ######  (du fait que g.(p-1) > variable LONG 32 bits) ######
    ######  factorisation p=g.q + r telle que qqs 0<z<p-1 ######
    ###### g.z mod p=| g.(z mod q) - r.[z/q] si c'est >0  ######
    ######           | g.(z mod q) - r.[z/q] + p sinon    ######
    ###### o� les seuls couples (q;r) conseill�s sont :   ######
    ######         (127773; 2836)  avec g=16807           ######
    ######         ( 44488; 3399)  avec g=48271           ######
    ######         ( 30845;23902)  avec g=69621           ######
    ######         From Numerical Recipes in C            ######
    ############################################################
*/
  current ^= MASK;
  k = current/q;
  current = g*(current - k*q) - r*k;     // current=(g*current)%q
  if (current < 0) current += p;
  xsi=(double)(current)/p;
  current ^= MASK;
  return xsi;
}

void LGM::Spool(ofstream & fichier)
{
  fichier<<endl<<"PRNG"<<endl<<"Multiplicative congruential method (Lewis, Goodman, Miller)"<<endl;
  fichier<<"Seed number is "<< seed <<endl;
  fichier.precision(3);
  /*
  fichier<<"Number of pseudo-random used in simulation\t"<<compteur<< ". This is " << 100*compteur/(pow(2.,31)-2) << " % use of LGM." << endl<<endl;
  */
}


LECUYER::LECUYER(long long s) : PseudoRandom(s) {}

#define IM1 2147483563
#define IM2 2147483399
#define AM (1.0/IM1)
#define IMM1 (IM1-1)
#define IA1 40014
#define IA2 40692
#define IQ1 53668
#define IQ2 52774
#define IR1 12211
#define IR2 3791
#define NTAB 32
#define NDIV (1+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
/** ############################################################
    ######       Algorithme s�quentiel de L'Ecuyer        ######
    ############################################################
    ######     Long period (> 2 � 10^18) random number    ######
    ######     generator of L�Ecuyer with Bays-Durham     ######
    ######     shuffle and added safeguards.              ######
    ######  Returns a uniform random deviate between 0.0  ######
    ######  and 1.0 (exclusive of the endpoint values).   ######
    ###### Call with idum a negative integer to initialize######
    ######      thereafter, do not alter idum between     ######
    ######        successive deviates in a sequence.      ######
    ######  RNMX should approximate the largest floating  ######
    ######           value that is less than 1.           ######
    ######         From Numerical Recipes in C            ######
    ############################################################
*/
double LECUYER::GetAlea()
{
    compteur += 1;
    int j;
    static long long idum2 = 123456789;
    static long long iy = 0;
    static long long iv[NTAB];
    if (current <= 0)                       /// Initialize.
    {
        if (-(current) < 1) current=1;      /// Be sure to prevent idum = 0.
        else current = -(current);
        idum2 = current;
        for (j=NTAB+7;j>=0;j--)
        {
            /// Load the shuffle table (after 8 warm-ups).
            k = (current)/IQ1;
            current = IA1*(current-k*IQ1)-k*IR1;
            if (current < 0) current += IM1;
            if (j < NTAB) iv[j] = current;
        }
        iy=iv[0];
    }
    k = (current)/IQ1;                      /// Start here when not initializing.
    current = IA1*(current-k*IQ1)-k*IR1;    /// Compute current=(IA1*current) % IM1 without
    if (current < 0) current += IM1;        /// overflows by Schrage�s method.
    k = idum2/IQ2;
    idum2 = IA2*(idum2-k*IQ2)-k*IR2;        /// Compute idum2=(IA2*current) % IM2 likewise.
    if (idum2 < 0) idum2 += IM2;
    j = iy/NDIV;                            /// Will be in the range 0..NTAB-1.
    iy = iv[j]-idum2;                       /// Here idum is shuffled, idum and idum2 are
    iv[j] = current;                        /// combined to generate output.
    if (iy < 1) iy += IMM1;
    if ((xsi=AM*iy) > RNMX) return RNMX;    /// Because users don�t expect endpoint values.
    else return xsi;
}


void LECUYER::Spool(ofstream & fichier)
{
  fichier<<endl<<"PRNG"<<endl<<"Sequential Random Generator of L'Ecuyer (ran2 of Numerical Recipes in C)"<<endl;
  fichier<<"Seed number is "<< seed <<endl;
  if ( seed > 0 ) fichier<<"warning\tL'Ecuyer RNG requires negative seed to properly initialize" <<endl;
  fichier.precision(3);
  fichier<<"Number of pseudo-random used in simulation\t"<<compteur
         << ". This is " << 100*compteur/2.31e18 << " % use of L'Ecuyer RNG." << endl<<endl;
}
