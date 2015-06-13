#ifndef AGENDA
#define AGENDA

/*!
 * \file agenda.h
 * \brief Agenda (Manager des évènements)
 * \author Guyet-Lagache
 */

 #include "evenement.h"
#include "projetmanager.h"

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
    //~Agenda();
public:
    /**
    * \brief Supprime un évènement
    * \param const QString& t : titre de l'évènement à supprimer
    */
    const QList<Evenement*>& getEvenements()const {return listeEvts;}
    QList<Evenement*> getEvenements(const QDate& date);
    void supprimerEvenement(Evenement* e);
    static Agenda& getInstance();
    void afficherListeEvts();
    void ajouterEvenement(Evenement *e);
    EvenementSimple* ajouterEvenementSimple(const QString &t, const QString &pers, const QDateTime &d, const QDateTime &f, const QString& lieu);
    EvenementTache *ajouterEvenementTache(const QString & titre,const QString &pers, const QDateTime &d, const QDateTime &f, Tache *tache);
    bool isExistant(const QString& id);
    Evenement* trouverEvenement(const QString& id);
    QString genererNewId();
    // void save(const QString& f);

};


#endif // AGENDA

