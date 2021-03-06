#include "projetmanager.h"

ProjetManager* ProjetManager::instance = 0;


Projet* ProjetManager::trouverProjet(QString titre){
    for (QVector<Projet*>::Iterator it = projets.begin(); it!= projets.end(); ++it)
        if (titre == (*it)->getTitre()) return (*it);
    return 0;
};

bool ProjetManager::isExistant(Projet *p){
    return isExistant(p->getTitre());
}


bool ProjetManager::isExistant(QString titre){
    for (QVector<Projet*>::Iterator it = projets.begin(); it!= projets.end(); ++it)
        if (titre == (*it)->getTitre()) return true;
    return false;
}

void ProjetManager::ajouterProjet(Projet* p){
    if (isExistant(p))
        throw CalendarException("Un projet porte déjà ce nom. Le projet n'a pas été créé.");
    projets.push_back(p);
}

Projet* ProjetManager::ajouterProjet(const QString& titre, const QDate& dispo, const QDate& deadline){
    Projet* p = new Projet(titre, dispo, deadline);
    ajouterProjet(p);
    return p;
}

void ProjetManager::supprimerTache(Tache* t){
    for(QVector<Projet*>::iterator it = projets.begin(); it!=projets.end() ;it++){
        (*it)->supprimerTache(t);
    }
}

void ProjetManager::supprimerProjet(const QString& titre){
    Projet* p=trouverProjet(titre);
    supprimerProjet(p);
};


void ProjetManager::supprimerProjet(Projet* projet){
    int i=0;
    QVector<Projet*>::const_iterator it= projets.begin();
    while((it != projets.end()) && ((*it) != projet)){
        ++it;
        i++;
    }
    if (it != projets.end()){
        delete projets[i];
        projets.remove(i);
    }
}

void ProjetManager::afficherProjets(){
    for (QVector<Projet*>::Iterator it= projets.begin(); it != projets.end(); ++it){
        try{
            throw CalendarException((*it)->getTitre());
        }catch (CalendarException e){
            e.afficherInfo();
        }
    }
}



ProjetManager& ProjetManager::getInstance(){
    if (instance==0){
        instance = new ProjetManager;
    }
    return *instance;
}

ProjetManager::ProjetManager(){}

