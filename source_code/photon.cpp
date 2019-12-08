#include "photon.hpp"
#include "constants.hpp"


Photon::Photon(float energy)
{
    E = energy;
    weight = 1;
    position = 0;
    cosTheta = 1;
    number = 1;
}

void Photon::Spool(ofstream& ofstr)
{
    ofstr << "Photon number : " << Write_d(number,10)
          << Write_d("energy = ",20) << Write_d(E,5)
          << Write_d("weight = ",20) << Write_d(weight,5)
          << Write_d("position = ",20) << Write_d(position,5)
          << Write_d("cosTheta = ",20) << Write_d(cosTheta, 5) << endl;
}

void Photon::FillLogFile()
{
    ofstream ofstr;
    ofstr.open("photons.log", ios::app);
    Spool(ofstr);
    ofstr.close();
}
