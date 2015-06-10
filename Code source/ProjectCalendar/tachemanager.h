#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H
#include "tache.h"

/*!
 * \file tachemanager.h
 * \brief TacheManager permettant de référencer toutes les tâches créées et donc d'éviter les doublons
 * \author Guyet-Lagache
 */

/**
 * \class TacheManager
 * \brief Conteneur des Taches
 *
 * TacheManager est un singleton.
 * Toutes les taches sont stockées dans l'instance de TacheManager, à leur création
 */
class TacheManager{
private:
    QVector<Tache*> taches;
    static TacheManager* instance;
    TacheManager();

public:
    void ajouterTache(Tache* t);
    void supprimerTache(const QString& id);
    void supprimerTache(Tache* t);
    static TacheManager& getInstance();

    /**
    * \brief Génère une nouvelle clef unique
    * \return chaîne de caractère créée aléatoirement, de longueur 5
    */
    QString genererNewId();

    bool isExistant(QString id);
    bool isExistant(Tache* t);
    Tache* trouverTache(QString id);

    void afficherTaches();

};



#endif // TACHEMANAGER_H

