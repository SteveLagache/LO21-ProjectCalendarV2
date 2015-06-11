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
    /**
    * \brief Supprime un projet
    * \param const QString& titre: titre du projet à supprimer
    */
    const QVector<Projet*>& getProjets() const {return projets;}
    void supprimerProjet(const QString& titre);
    void supprimerProjet(Projet* p);
    void supprimerTache(Tache *t);
    static ProjetManager& getInstance();
    void afficherProjets();
    void ajouterProjet(Projet *p);
    Projet* ajouterProjet(const QString& titre, const QDate& dispo, const QDate& deadline);
    bool isExistant(QString titre);
    bool isExistant(Projet*p);
    Projet* trouverProjet(QString titre);

};




#endif // PROJETMANAGER_H

