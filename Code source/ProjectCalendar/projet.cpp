#include "projet.h"


void Projet::setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e) {
    if (e<disp)
    {
        echeance=disp;
        try{
            throw CalendarException("Problème dans les dates du projet:\n( date echéance < date disponibilité )\nLa date d'échéance a été modifiée");
        }
        catch(CalendarException e){
            e.afficherWarning();
        }
    }
    else echeance=e;

    disponibilite=disp;
}



Projet::Projet(const QString& titre, const QDate& dispo, const QDate& deadline){
    this->titre = titre;
    setDatesDisponibiliteEcheance(dispo, deadline);
}



//Projet::~Projet(){
//    for (QList<Tache*>::Iterator it= taches.begin(); it != taches.end(); ++it){
//        delete *it;
//    }
//}

void Projet::ajouterTache(Tache* t){
    bool changement = false;
    if (t->getDateDisponibilite() < this->disponibilite){ // tache dispo inférieur à projet dispo
        t->setDatesDisponibiliteEcheance(this->getDateDisponibilite(), t->getDateEcheance());
        changement= true;
    }
    if (t->getDateEcheance() > this->echeance){ // tache echance sup à projet echeance
        t->setDatesDisponibiliteEcheance(t->getDateDisponibilite(), this->getDateEcheance());
        changement = true;
    }
    try {
        if (changement) throw CalendarException("Problème dans les dates de la tâche par rapport au projet:\nLes dates de disponibilité et d'échéances n'étaient pas comprises dans les dates du projet\nLes dates de la tâche ont donc été modifiées");
        }
    catch ( CalendarException e){
        e.afficherWarning();
    }

    taches.push_back(t);
}


void Projet::afficherTaches(){
    for (QList<Tache*>::Iterator it= taches.begin(); it != taches.end(); ++it){
    try{
        throw CalendarException((*it)->getTitre());
    }catch (CalendarException e){
            e.afficherInfo();
        }
    }
}
