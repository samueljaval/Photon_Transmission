#include "collision.hpp"

//----------- types of collisions


void PE::DoCollision(Photon* photon)
{
    photon->weight = 0;
}


void CE::DoCollision(Photon* photon)
{
    bool boolean = true;
    double energy = photon->E;
    double r = 0, alpha = energy/0.511 , one_over_alpha = 1./alpha;

    if ( energy < 1.500 )
    {
        // Kahn's rejection algorithm
        while (boolean)
        {
            if (rando->GetAlea() <= (1+2*alpha)/(9+2*alpha))
            {
                r = 1 + 2*alpha*rando->GetAlea();
                if (rando->GetAlea() <= 4/r*(1-1/r)) boolean = false;
            }
            else
            {
                r = (1 + 2*alpha)/(1 + 2*alpha*rando->GetAlea());
                if (rando->GetAlea() <= 0.5*(pow((one_over_alpha*(1-r)+1),2)+1/r)) boolean = false;
            }
        }
    }
    else
    {
        // Koblinger's direct sampling algorithm
        double beta  = 1 + 2*alpha;
        double gamma = 1 - pow(beta,-2);
        double p1 = 2./alpha;
        double p2 = (1 - (1 + beta)*pow(alpha,-2))*log(beta);
        double p3 = p1;
        double p4 = gamma/2;
        double ptot = p1 + p2 + p3 + p4;

        p1 /= ptot; p2 /= ptot; p3 /= ptot; p4 /= ptot;

        double xsi = rando->GetAlea();
        double ksi = rando->GetAlea();

        if ( xsi <  p1                                 )  r = 1 + 2*alpha*ksi           ;
        if ( xsi >= p1           && xsi < p1 + p2      )  r = pow(beta,ksi)             ;
        if ( xsi >= p1 + p2      && xsi < p1 + p2 + p3 )  r = beta/(1 + 2*alpha*ksi)    ;
        if ( xsi >= p1 + p2 + p3                       )  r = pow( (1-gamma*ksi), -0.5) ;
    }

    CosDev = 1-one_over_alpha*(r-1);
    if (abs(CosDev) > 1)  { cout <<endl<<"++++++ FATAL ERROR : |CosDev| > 1"; exit(0); }
    double kappa = 2 * PI * rando->GetAlea();

    energy /= r;
    photon->E = energy;
    photon->cosTheta = CosDev;

}


void PP::DoCollision(Photon* photon)
{
    photon->weight == 2;
    double negOrPos = rando->GetAlea();                      //GetAlea() returns a randomom number between 0 and 1
    double random_ = rando->GetAlea();
    double theta = (negOrPos < 0.5) ? random_ : -random_;
    theta *= PI;   // * pi to get an angle between zero and pi
    photon->cosTheta =  cos(theta);
    //change of energy calculation
}
