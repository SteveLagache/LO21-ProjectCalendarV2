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
    ///
    /// \brief Retourne la liste de tous les évènements
    /// \return Tous les évènements (listeEvts)
    ///
    const QList<Evenement*>& getEvenements()const {return listeEvts;}
    ///
    /// \brief Retourne une liste d'évènements sur une semaine
    /// \param const QDate& date : date voulue
    /// \return Evènements de la semaine donnée par le paramètre
    ///
    QList<Evenement*> getEvenements(const QDate& date);
    ///
    /// \brief Retourne une liste d'évènements liés à un projet
    /// \param Projet* p : pointeur sur le projet voulu
    /// \return Liste d'évènements liés au projet passé en paramètre
    ///
    QList<Evenement*> getEvenements(Projet* p);
    /**
    * \brief Supprime un évènement
    * \param Evenement* e : pointeur sur l'évènement à supprimer
    */
    void supprimerEvenement(Evenement* e);
    static Agenda& getInstance();
    ///
    /// \brief Affiche la liste des évènements
    ///
    void afficherListeEvts();
    ///
    /// \brief Ajoute un évènement
    /// \param Evenement* e : pointeur sur évènement à ajouter
    ///
    void ajouterEvenement(Evenement *e);
    EvenementSimple* ajouterEvenementSimple(const QString &t, const QString &pers, const QDateTime &d, const QDateTime &f, const QString& lieu);
    EvenementTache *ajouterEvenementTache(const QString & titre, const QString &pers, const QDateTime &d, const QDateTime &f, TacheUnitaire *tache);
    bool isExistant(const QString& id);
    ///
    /// \brief Recherche un évènement dans la liste
    /// \param const QString& id : id de l'évènement à chercher
    /// \return Pointeur sur l'évènement trouvé
    ///
    Evenement* trouverEvenement(const QString& id);
    /**
    * \brief Génère une nouvelle clef unique
    * \return chaîne de caractère créée aléatoirement, de longueur 5
    */
    QString genererNewId();
    /**
    * \brief Exporte tous les évènements
    *
    * Exporte l'ensemble des évènements dans un fichier XML
    */
    void export_general();
    ///
    /// \brief Exporte les évènements d'une semaine
    /// \param const QDate& date : date de la semaine voulue
    ///
    void export_semaine(const QDate& date);
    ///
    /// \brief Exporte les évènements liés à un projet
    /// \param Projet* p : pointeur sur le projet voulu
    ///
    void export_projet(Projet* p);

};


#endif // AGENDA

