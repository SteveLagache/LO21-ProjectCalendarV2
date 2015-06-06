#ifndef AGENDA
#define AGENDA

/*!
 * \file agenda.h
 * \brief Agenda (Manager des évènements)
 * \author Guyet-Lagache
 */

 #include "evenement.h"

/**
 * \class Agenda
 * \brief Agenda contient des évènements
 */
class Agenda {
private:
    QList<Evenement*> listeEvts;
    // Liste chainée de pointeurs d'évènements

public:

};


#endif // AGENDA

