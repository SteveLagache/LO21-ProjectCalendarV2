#include "tache.h"
#include "exception.h"

Tache::Tache(const QString& titre, const QDate& dispo, const QDate& deadline){
    this->titre = titre;
    try{
        setDatesDisponibiliteEcheance(dispo, deadline);
    }
    catch(CalendarException e){
        e.afficherWarning();
    }
}

void Tache::setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e) {
    if (e<disp)
    {
        throw CalendarException("Problème dans les dates de la tâche:\n( date echéance < date disponibilité )\n La date d'échéance a été modifiée");
        echeance=disp;
    }
    else echeance=e;

    disponibilite=disp;

}



TacheComposite::~TacheComposite(){
    for (QList<Tache*>::Iterator it= sousTaches.begin(); it != sousTaches.end(); ++it){
        delete *it;
    }
}

void TacheComposite::ajouterSousTache(Tache* t){
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
