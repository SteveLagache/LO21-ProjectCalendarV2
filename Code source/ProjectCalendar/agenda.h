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
 *
 * Agenda est un singleton
 * Tous les évènements sont stockés dans l'instance de Agenda
 */
class Agenda {
private:
    QList<Evenement*> listeEvts;
    // Liste chainée de pointeurs d'évènements
    static Agenda* instance;
    Agenda();
    ~Agenda();
public:
    /**
    * \brief Supprime un évènement
    * \param const QString& t : titre de l'évènement à supprimer
    */
    void supprimerEvenement(const QString& t);
    static Agenda& getInstance();
    void afficherListeEvts();
    void ajouterEvenement(Evenement *e);
    void ajouterEvenement(const QString& t, const QString& pers, const QDateTime& d, const QDateTime& f);
    bool isExistant(Evenement *e);

};


#endif // AGENDA

