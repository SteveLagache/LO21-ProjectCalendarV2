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

void Projet::setTitre(const QString& str) {
    this->titre = "/!\\ TITRE EN MODIFICATION /!\\";
    ProjetManager& pm= ProjetManager::getInstance();
    if (pm.trouverProjet(str) != 0)
        throw CalendarException("Il existe déjà un projet avec ce titre");
    titre= str;
 }


Projet::Projet(const QString& titre, const QDate& dispo, const QDate& deadline){
    this->titre = titre;
    setDatesDisponibiliteEcheance(dispo, deadline);
}






Projet::~Projet(){
    while (taches.size() != 0){
        supprimerTache(taches[0]);
    }
}

void Projet::ajouterTache(Tache* t){
    bool changement = false;
    if (t->getDateDisponibilite() < this->disponibilite){ // tache dispo inférieur à projet dispo
        t->setDatesDisponibiliteEcheance(disponibilite, t->getDateEcheance());
        changement= true;
    }
    if (t->getDateEcheance() > this->echeance){ // tache echance sup à projet echeance
        t->setDatesDisponibiliteEcheance(t->getDateDisponibilite(), echeance);
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


bool Projet::contientTache(Tache* t){
    bool retour = false;
    for (QList<Tache*>::const_iterator it = getTaches().begin(); it!= getTaches().end(); it++ ){
        if ((*it) == t)
            return true;
        else if((*it)->getType()=="TacheComposite"){
            TacheComposite* tc= dynamic_cast<TacheComposite*>(*it);
            retour = tc->contientDescendant(t);
            if (retour == true)return true;
        }
    }
    return false;
}

void Projet::supprimerTache(Tache * t){
        int i=0;
        QList<Tache*>::Iterator it= taches.begin();
        while((it != taches.end()) && ((*it) != t)){
            if((*it)->getType()=="TacheComposite"){
                TacheComposite* tc = dynamic_cast<TacheComposite*>(*it);
                tc->supprimerSousTache(t);
            }
            ++it;
            i++;
        }
        if (it != taches.end())
           taches.removeAt(i);
     }


void Projet::monterPrecedence(Tache *t){
    if (taches[0] ==  t) throw CalendarException("Cette tâche ne peut pas être plus prioritaire");
    int i= 1;
    while(i < taches.size()-1 && taches[i] !=  t){
        i++;
    }
    if (taches[i] ==  t){
        taches.swap(i-1, i);
    }
    else throw CalendarException("La tâche à monter n'appartient pas au projet");
}


void Projet::descendrePrecedence(Tache *t){
    if (taches[taches.size()-1] ==  t) throw CalendarException("Cette tâche ne peut pas être moins prioritaire");
    int i= 0;
    while(i < taches.size()-2 && taches[i] !=  t){
        i++;
    }
    if (taches[i] ==  t){
        taches.swap(i, i+1);
    }
    else throw CalendarException("La tâche à monter n'appartient pas au projet");
};


void Projet::afficherTaches(){
    for (QList<Tache*>::Iterator it= taches.begin(); it != taches.end(); ++it){
    try{
        throw CalendarException((*it)->getTitre());
    }catch (CalendarException e){
            e.afficherInfo();
        }
    }
}
