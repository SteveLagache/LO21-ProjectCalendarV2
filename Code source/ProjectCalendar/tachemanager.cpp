#include "tachemanager.h"
#include "outils.h"
#include "projetmanager.h"
#include <QtDebug>


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

TacheComposite* TacheManager::ajouterTacheComposite(const QString &titre, QDate debut, QDate fin){
    TacheComposite* tc= new TacheComposite(titre, debut, fin);
    ajouterTache(tc);
    return tc;
}

TacheUnitaire* TacheManager::ajouterTacheUnitaire(const QString& titre, QDate debut, QDate fin, Duree duree, bool preemp){
    TacheUnitaire* tu= new TacheUnitaire(titre, debut, fin, duree, preemp);
    ajouterTache(tu);
    return tu;
}


void TacheManager::supprimerTache(const QString& id){

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
    int index = taches.indexOf(t);
    if(index == -1) //Pas trouver
    {
        qDebug() << "Tache introuvable";
        return;
    }
    qDebug() << index;
    taches.remove(index);
    qDebug() << "Tache supprimée";
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


Tache* TacheManager::remplacerTache(Tache* t, Tache* t2){
    Tache* old =t;
    t = t2;
    supprimerTache(old);
    return t;
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
