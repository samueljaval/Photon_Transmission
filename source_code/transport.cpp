#include "transport.hpp"

void Transport::linearTransport(Photon * photon)
{
    // let us compute photon.position
    linAtenuation = data->medium->GetLinearAttenuation(photon->E);
    float length = (-1/linAtenuation) * log(rando->GetAlea()) * photon->cosTheta;
    photon->position += length;

    if (photon->position > data->medium->thickness || photon->position < 0)  //if photon is outside the medium
    {
        if ( photon->position > data->medium->thickness )
        {
            data->coldside->Score(photon);
            if (TRACE) photon->FillLogFile();
            data->doserate->Score(photon);
        }
        if ( photon->position < 0 )
        {
            data->hotside->Score(photon);
            if (TRACE) photon->FillLogFile();
        }
    }
    else        /// the photon is inside the medium
    {
        interaction = data->medium->GetInteraction(photon->E, rando->GetAlea());

        if (interaction == ABSORPTION_PE)      {collision = new PE(); number_PE ++; }    //PE = Photoelectric absorption, cf. Einstein 1905
        if (interaction == INC_SCATTERING_CE)  {collision = new CE(); number_CE ++; }    //CE = Compton effect
        if (interaction == ABSORPTION_PP )     {collision = new PP(); number_PP ++; }    //PP = Pair production

        collision->DoCollision(photon);
        if (collision != NULL ) delete collision;                    // now we have used collision to get the modified photon so we can delete it
        if ( photon->weight != 0 ) Transport::linearTransport(photon); //using recursion to create the photon path
    }
}

void Transport::Spool(string name)
{
    ofstream ofstr;
    ofstr.open(name, ios::app);
    ofstr << number_PP << "         is the total number of pair productions" << endl;
    ofstr << number_CE << "         is the total number of Compton effects" << endl;
    ofstr << number_PE << "         is the total number of photoelectric absorptions" << endl;
    ofstr.close();
}

