#include "outils.h"



QString randomString(unsigned int len){

    QString str;
    QString alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (unsigned int i = 0; i < len; ++i) {
        str += alphanum[rand() % (alphanum.size() - 1)];
    }

    return str;
}
