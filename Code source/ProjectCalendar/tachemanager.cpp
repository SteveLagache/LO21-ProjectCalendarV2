#include "tachemanager.h"
#include "outils.h"
#include "projetmanager.h"



TacheManager* TacheManager::instance=0;

void TacheManager::ajouterTache(Tache* t){
    try {
        if (isExistant(t))
            throw CalendarException("Une tâche a déjà cet id");
        else taches.push_back(t);
    }
    catch(CalendarException e){
        e.afficherWarning();
    }
}



void TacheManager::supprimerTache(const QString& id){

    ProjetManager& pm = ProjetManager::getInstance();
    pm.supprimerTache( id);

    QVector<Tache*>::Iterator it= taches.begin();
    int j=0;
    while((it != taches.end()) && ((*it)->getId() != id)){
            ++it;
            j++;
        }
        if (it != taches.end()){
           delete taches[j];
           taches.remove(j);
           }
};


void TacheManager::supprimerTache(Tache* t){
    supprimerTache(t->getId());
};




QString TacheManager::genererNewId(){
    QString newId;
    do  { newId = randomString(5);
        } while (isExistant(newId));
    return newId;
}



bool TacheManager::isExistant(QString id){
    for (QVector<Tache*>::Iterator it = taches.begin(); it!= taches.end(); ++it)
        if (id == (*it)->getId()) return true;
    return false;
}

bool TacheManager::isExistant(Tache* t){
    return isExistant(t->getId());
}

TacheManager::TacheManager(){}

TacheManager& TacheManager::getInstance(){
    if (instance==0){
       try{
            throw CalendarException("Création du TacheManager");
       }
       catch(CalendarException e){
            e.afficherInfo();
       }

       instance = new TacheManager;
    }
    return *instance;
};


Tache* TacheManager::trouverTache(QString id){
    for (QVector<Tache*>::Iterator it = taches.begin(); it!= taches.end(); ++it)
        if (id == (*it)->getId()) return (*it);
    return 0;
};


void TacheManager::afficherTaches(){
    for (QVector<Tache*>::Iterator it= taches.begin(); it != taches.end(); ++it){
    try{
        throw CalendarException((*it)->getId() +" -- "+(*it)->getTitre());
    }catch (CalendarException e){
            e.afficherInfo();
        }
    }
}
