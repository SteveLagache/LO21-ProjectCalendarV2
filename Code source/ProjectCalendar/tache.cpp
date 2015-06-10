#include "tache.h"
#include "exception.h"
#include "tachemanager.h"

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

void TacheComposite::supprimerSousTache(const QString id){
    int i=0;
    QList<Tache*>::Iterator it= sousTaches.begin();
    while((it != sousTaches.end()) && ((*it)->getId() != id)){
        if((*it)->getType()=="TacheComposite"){
            TacheComposite* tc = dynamic_cast<TacheComposite*>(*it);
            tc->supprimerSousTache(id);
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
        supprimerSousTache(sousTaches[0]->getId());
    }
};

TacheUnitaire::~TacheUnitaire(){
    QMessageBox::information(0, "COUcd","hghjg");
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
