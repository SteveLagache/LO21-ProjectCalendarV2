#include "tache.h"
#include "exception.h"
#include "tachemanager.h"
#include "projetmanager.h"

Tache::Tache(const QString& titre, const QDate& dispo, const QDate& deadline){
    TacheManager& tm = TacheManager::getInstance();
    id= tm.genererNewId();
    this->titre = titre;
    setDatesDisponibiliteEcheance(dispo, deadline);
}

void Tache::setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e) {
    if (e<disp)
    {
        echeance=disp;
    try{
            throw CalendarException("Problème dans les dates de la tâche:\n( date echéance < date disponibilité )\nLa date d'échéance a été modifiée");
        }
        catch(CalendarException e){
            e.afficherWarning();
        }
    }
    else echeance=e;

    disponibilite=disp;
}

void TacheComposite::monterSousTache(Tache *t){
        if (sousTaches[0] ==  t) throw CalendarException("Cette tâche ne peut pas être plus prioritaire");
        int i= 1;
        while(i < sousTaches.size()-1 && sousTaches[i] !=  t){
            i++;
        }
        if (sousTaches[i] ==  t){
            sousTaches.swap(i-1, i);
        }
        else throw CalendarException("La sous-tâche à monter n'appartient pas à la tâches");
}

void TacheComposite::descendreSousTache(Tache *t){
    if (sousTaches[sousTaches.size()-1] ==  t) throw CalendarException("Cette tâche ne peut pas être moins prioritaire");
    int i= 0;
    while(i < sousTaches.size()-2 && sousTaches[i] !=  t){
        i++;
    }
    if (sousTaches[i] ==  t){
        sousTaches.swap(i, i+1);
    }
    else throw CalendarException("La tâche à monter n'appartient pas au projet");
};



TacheComposite* Tache::getTacheMere(){
    TacheManager& tm = TacheManager::getInstance();
    const QVector<Tache*>& taches = tm.getTaches();
    for (QVector<Tache*>::const_iterator it = taches.begin(); it!= taches.end(); it++){
        if ((*it)->getType()== "TacheComposite")
        {
            TacheComposite* tc = dynamic_cast<TacheComposite*>(*it);
            const QList<Tache*>& sousTaches = tc->getSousTaches();
            for (QList<Tache*>::const_iterator it2= sousTaches.begin(); it2!=sousTaches.end(); it2++){
                if ((*it2)==this) return dynamic_cast<TacheComposite*>(*it);
            }
        }
    }
    return 0;
};

Projet* Tache::getProjetPere(){
    ProjetManager& pm= ProjetManager::getInstance();
    for (QVector<Projet*>::const_iterator it= pm.getProjets().begin(); it!=pm.getProjets().end(); it++)
    {
        if ((*it)->contientTache(this)) return (*it);
    }
    return 0;
};

bool TacheComposite::contientFils(Tache * t){
    for (QList<Tache*>::iterator it = sousTaches.begin(); it != sousTaches.end(); it++){
        if ((*it) == t)
            return true;
    }
    return false;
}

bool TacheComposite::contientDescendant(Tache * t){
    bool retour = false;
    for (QList<Tache*>::const_iterator it = sousTaches.begin(); it != sousTaches.end(); it++){
        if ((*it) == t)
            return true;
        else if((*it)->getType()=="TacheComposite"){
            TacheComposite* tc= dynamic_cast<TacheComposite*>(*it);
            retour = tc->contientDescendant(t);
            if (retour == true)return true;
        }
    }
    return false;
};


//Tache::~Tache(){};

//TacheUnitaire::~TacheUnitaire(){}


//TacheComposite::~TacheComposite(){
//    for (QList<Tache*>::Iterator it= sousTaches.begin(); it != sousTaches.end(); ++it){
//        delete *it;
//    }
//}

void TacheComposite::ajouterSousTache(Tache* t){
    bool changement = false;
    if (t->getDateDisponibilite() < this->disponibilite){ // sous-tache dispo inférieur à tacheComposite dispo
        t->setDatesDisponibiliteEcheance(disponibilite, t->getDateEcheance());
        changement= true;
    }
    if (t->getDateEcheance() > this->echeance){ // tsous-tache echance sup à tacheComposite echeance
        t->setDatesDisponibiliteEcheance(t->getDateDisponibilite(), echeance);
        changement = true;
    }
    try {
        if (changement) throw CalendarException("Problème dans les dates de la sous-tâche par rapport à la tâche composite:\nLes dates de disponibilité et d'échéances n'étaient pas comprises dans les dates de la tache composite\nLes dates de la sous-tâche ont donc été modifiées");
        }
    catch ( CalendarException e){
        e.afficherWarning();
    }
    sousTaches.push_back(t);
}

void TacheComposite::supprimerSousTache(Tache* t){
    int i=0;
    QList<Tache*>::Iterator it= sousTaches.begin();
    while((it != sousTaches.end()) && ((*it)!= t)){
        if((*it)->getType()=="TacheComposite"){
            TacheComposite* tc = dynamic_cast<TacheComposite*>(*it);
            tc->supprimerSousTache(t);
        }
        ++it;
        i++;
    }
    if (it != sousTaches.end())
       sousTaches.removeAt(i);
};


void TacheComposite::afficherSousTaches(){
    for (QList<Tache*>::Iterator it= sousTaches.begin(); it != sousTaches.end(); ++it){
    try{
        throw CalendarException((*it)->getTitre());
    }catch (CalendarException e){
            e.afficherInfo();
        }
    }
}

TacheComposite::~TacheComposite(){
    while (sousTaches.size()){
        TacheManager& tm = TacheManager::getInstance();
        tm.supprimerTache(sousTaches[0]);
    }
};

TacheUnitaire::~TacheUnitaire(){
    ProjetManager& pm = ProjetManager::getInstance();
    pm.supprimerTache(this);
};

void TacheUnitaire::setDuree(const Duree& newDuree) {
    if (!preemptive){
        if (newDuree > Duree(12,0))
        {
            duree= Duree(12,0);
            throw CalendarException("La durée d'une tâche non préemptive ne peut être supérieure à 12 heures. La durée de la tâche a donc été modfifiée.");
        } else duree = newDuree;
    } else duree = newDuree;

}
