#include "time.h"

bool operator>(const Duree & d, const Duree & d2){
    return (d.getHeure() > d2.getHeure() || (d.getHeure() >= d2.getHeure() && d.getMinute()>0));
};
