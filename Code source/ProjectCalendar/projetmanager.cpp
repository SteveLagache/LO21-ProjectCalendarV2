#include "projetmanager.h"

ProjetManager* ProjetManager::instance = 0;

bool ProjetManager::isExistant(Projet* p){
    for (QVector<Projet*>::Iterator it = projets.begin(); it!= projets.end(); ++it)
        if (p->getTitre() == (*it)->getTitre()) return true;
    return false;
}

void ProjetManager::ajouterProjet(Projet* p){
    try {
        if (isExistant(p))
            throw CalendarException("Un projet porte déjà ce nom. Le projet n'a pas été créé.");
        else projets.push_back(p);
    }
    catch(CalendarException e){
        e.afficherWarning();
    }
}

void ProjetManager::ajouterProjet(const QString& titre, const QDate& dispo, const QDate& deadline){
    Projet* p = new Projet(titre, dispo, deadline);
    ajouterProjet(p);
}


void ProjetManager::supprimerProjet(const QString& titre){
    int i=0;
    QVector<Projet*>::Iterator it= projets.begin();
    while((it != projets.end()) || ((*it)->getTitre() != titre)){
        ++it;
        i++;
    }
    if (it == projets.end())
        return;
    else projets.remove(i);
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
       try{
            throw CalendarException("Création du ProjetManager");
       }
       catch(CalendarException e){
            e.afficherInfo();
       }

       instance = new ProjetManager;
    }
    return *instance;
}

ProjetManager::ProjetManager(){}

ProjetManager::~ProjetManager(){
     for (QVector<Projet*>::Iterator it = projets.begin(); it!= projets.end(); ++it)
         delete (*it);
};

