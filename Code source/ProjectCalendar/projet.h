#ifndef PROJET_H
#define PROJET_H

/*!
 * \file projet.h
 * \brief Projets
 * \author Guyet-Lagache
 */

#include "tache.h"
#include "projetmanager.h"

/**
 * \class Projet
 * \brief Projet
 *
 * Un projet est caractérisé par :
 *      des tâches
 *      un titre (permettant d’en saisir la nature)
 *      une date de disponibilité (date à laquelle on pourra commencer le projet)
 *      une date d'écheance (date à laquelle le projet doit être terminé)
 * L’échéance d’un projet est une borne supérieure de l’ensemble des échéances des tâches de ce projet.
 *
 */
class Projet{
private:
    friend class ProjetManager;
    QList<Tache*> taches;
    QString titre;
    QDate disponibilite;
    QDate echeance;

public:
    Projet(const QString& titre, const QDate& dispo, const QDate& deadline);
    ~Projet();

    QList<Tache*>& getTaches() { return taches;};

    QString getTitre() const { return titre; }
    void setTitre(const QString& str);

    QDate getDateDisponibilite() const { return disponibilite; }
    QDate getDateEcheance() const { return echeance; }

    void supprimerTache(const QString id);

    /**
    * \brief Vérifie que (date dispo < date échéance) avant de les appliquer au projet
    * \param const QDate& dispo : date de disponibilité du projet,
    * const QDate& deadline : date d'échéance du projet
    */
    void setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e);

    void afficherTaches();

    /**
    * \brief Ajoute une tâche au projet
    * \param Tache* t: pointeur sur la tâche à ajouter.
    *
    */
    void ajouterTache(Tache* t);

};

#endif // PROJET_H

