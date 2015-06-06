#include <agenda.h>


Agenda* Agenda::instance = 0;

bool Agenda::isExistant(Evenement* e){
    for (QList<Evenement*>::Iterator it = listeEvts.begin(); it!= listeEvts.end(); ++it)
        if (e->getTitre() == (*it)->getTitre()) return true;
    return false;
}

void Agenda::ajouterEvenement(Evenement* e){
    try {
        if (isExistant(e))
            throw CalendarException("Un évènement porte déjà ce nom. L'évènement n'a pas été créé.");
        else listeEvts.push_back(e);
    }
    catch(CalendarException e){
        e.afficherWarning();
    }
}

void Agenda::ajouterEvenement(const QString& t, const QString& pers, const QDateTime& d, const QDateTime& f){
    Evenement* e = new Evenement(t, pers, d, f);
    ajouterEvenement(e);
}


void Agenda::supprimerEvenement(const QString& t){
    int i=0;
    QList<Evenement*>::Iterator it= listeEvts.begin();
    while((it != listeEvts.end()) && ((*it)->getTitre() != t)){
        ++it;
        i++;
    }
    if (it == listeEvts.end()) {
        try {
            throw CalendarException("Evènement non trouvé");
        }
        catch (CalendarException e){
            e.afficherInfo();
        }
        return;
    }
    else listeEvts.removeAt(i);
}

void Agenda::afficherListeEvts(){
    for (QList<Evenement*>::Iterator it= listeEvts.begin(); it != listeEvts.end(); ++it){
        try {
            throw CalendarException((*it)->getTitre());
        }
        catch (CalendarException e){
            e.afficherInfo();
        }
    }
}




Agenda& Agenda::getInstance(){
    if (instance==0){
       try{
            throw CalendarException("Création de l'Agenda");
       }
       catch(CalendarException e){
            e.afficherInfo();
       }

       instance = new Agenda;
    }
    return *instance;
}

Agenda::Agenda(){}

Agenda::~Agenda(){
     for (QList<Evenement*>::Iterator it = listeEvts.begin(); it!= listeEvts.end(); ++it)
         delete (*it);
};

