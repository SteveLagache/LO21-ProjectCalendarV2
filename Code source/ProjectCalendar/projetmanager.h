#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H
/*!
 * \file projetmanager.h
 * \brief Manager des projets
 * \author Guyet-Lagache
 */

#include<QVector>
#include"projet.h"


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
    QVector<Projet*>& getProjets() {return projets;}
    void supprimerProjet(const QString& titre);
    static ProjetManager& getInstance();
    void afficherProjets();
    void ajouterProjet(Projet *p);
    void ajouterProjet(const QString& titre, const QDate& dispo, const QDate& deadline);
    bool isExistant(Projet *p);

};




#endif // PROJETMANAGER_H

