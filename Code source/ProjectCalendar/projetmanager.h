#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H
/*!
 * \file projetmanager.h
 * \brief Manager des projets
 * \author Guyet-Lagache
 */

#include <QVector>
#include "projet.h"
#include "tache.h"

class Tache;
class Projet;

/**
 * \class ProjetManager
 * \brief Conteneur des projets
 *
 * ProjetManager est un singleton.
 * Tous les projets sont stocké dans l'instance de ProjetManager
 */
class ProjetManager{
private:
    QVector<Projet*> projets;
    static ProjetManager* instance;
    ProjetManager();
    // ~ProjetManager();

public:
    ///
    /// \brief Renvoie l'ensemble des projets
    /// \return Liste de pointeurs sur projets
    ///
    const QVector<Projet*>& getProjets() const {return projets;}
    /**
    * \brief Supprime un projet
    * \param Projet* projet : pointeur sur le projet à supprimer
    */
    void supprimerProjet(Projet *projet);
    /**
    * \brief Supprime un projet
    * \param const QString& titre: titre du projet à supprimer
    */
    void supprimerProjet(const QString& titre);
    /**
    * \brief Supprime une tâche
    * \param Tache* t : pointeur sur la tâche à supprimer
    */
    void supprimerTache(Tache *t);
    static ProjetManager& getInstance();
    ///
    /// \brief Affiche les projets, utilisée dans le développement
    ///
    void afficherProjets();
    ///
    /// \brief Ajouter un projet
    /// \param Projet* p : pointeur sur le projet à ajouter
    ///
    void ajouterProjet(Projet *p);
    ///
    /// \brief Ajouter un projet
    /// \param const QString& titre : titre du projet,
    /// \param const QDate& dispo : date de disponibilité du projet,
    /// \param const QDate& deadline : date d'échéance du projet
    /// \return pointeur sur le projet ajouté
    ///
    Projet* ajouterProjet(const QString& titre, const QDate& dispo, const QDate& deadline);
    bool isExistant(QString titre);
    bool isExistant(Projet*p);
    ///
    /// \brief Recherche un projet
    /// \param const QString& titre : titre du projet à chercher
    /// \return Pointeur sur le projet trouvé
    ///
    Projet* trouverProjet(QString titre);

};




#endif // PROJETMANAGER_H

