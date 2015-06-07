#include "tache.h"
#include "exception.h"
#include "tachemanager.h"

Tache::Tache(const QString& titre, const QDate& dispo, const QDate& deadline){
    TacheManager& tm= TacheManager::getInstance();
    this->id = tm.genererNewId();
    this->titre = titre;
    setDatesDisponibiliteEcheance(dispo, deadline);
    tm.ajouterTache(this);
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
        t->setDatesDisponibiliteEcheance(this->getDateDisponibilite(), t->getDateEcheance());
        changement= true;
    }
    if (t->getDateEcheance() > this->echeance){ // tsous-tache echance sup à tacheComposite echeance
        t->setDatesDisponibiliteEcheance(t->getDateDisponibilite(), this->getDateEcheance());
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


void TacheComposite::afficherSousTaches(){
    for (QList<Tache*>::Iterator it= sousTaches.begin(); it != sousTaches.end(); ++it){
    try{
        throw CalendarException((*it)->getTitre());
    }catch (CalendarException e){
            e.afficherInfo();
        }
    }
}
