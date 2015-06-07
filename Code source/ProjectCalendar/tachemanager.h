#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H
#include "tache.h"

/*!
 * \file tachemanager.h
 * \brief TacheManager permettant de référencer toutes les tâches créées et donc d'éviter les doublons
 * \author Guyet-Lagache
 */


class TacheManager{
private:
    QVector<Tache*> taches;
    static TacheManager* instance;
    TacheManager();

public:
    void ajouterTache(Tache* t);
    static TacheManager& getInstance();
    QString genererNewId();
    bool isExistant(QString id);
    bool isExistant(Tache* t);
    void afficherTaches();

};



#endif // TACHEMANAGER_H

