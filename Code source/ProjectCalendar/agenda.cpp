#include <agenda.h>
#include <outils.h>

Agenda* Agenda::instance = 0;

bool Agenda::isExistant(const QString &id ){
    for (QList<Evenement*>::Iterator it = listeEvts.begin(); it!= listeEvts.end(); ++it)
        if (id == (*it)->getId()) return true;
    return false;
}

Evenement *Agenda::trouverEvenement(const QString &id)
{
    for (QList<Evenement*>::Iterator it = listeEvts.begin(); it!= listeEvts.end(); ++it)
        if (id == (*it)->getId()) return (*it);
    return 0;
}


void Agenda::ajouterEvenement(Evenement* e){
    try {
        if (isExistant(e->getId()))
            throw CalendarException("Cet évènement a déjà été ajouté à l'agenda");
        else {
            if (listeEvts.size() == 0)
                listeEvts.push_back(e);
            else if (listeEvts[0]->getDateDebut() > e->getDateFin())
                listeEvts.insert(0, e);
            else {
                int i= 1;
                QList<Evenement*>::Iterator it = listeEvts.begin();
                it++;
                while ((it != listeEvts.end()) && ((*it)->getDateFin() < e->getDateDebut())) {
                    i++;
                    it++;
                }
                if (it == listeEvts.end())
                    listeEvts.push_back(e);
                else {
                    if (it == listeEvts.end())
                        listeEvts.push_back(e);
                    else if ((*it)->getDateDebut() > e->getDateFin())
                        listeEvts.insert(i, e);
                    else
                        throw CalendarException("On ne peut pas progammer 2 évènements en même temps");
                }
            }
        }
    }
    catch(CalendarException e){
        e.afficherWarning();
    }
}

EvenementSimple *Agenda::ajouterEvenementSimple(const QString &t, const QString &pers, const QDateTime &d, const QDateTime &f, const QString& lieu)
{
    EvenementSimple* e = new EvenementSimple(t, pers, d, f, lieu);
    ajouterEvenement(e);
    return e;
}


EvenementTache *Agenda::ajouterEvenementTache(const QString &titre, const QString &pers, const QDateTime &d, const QDateTime &f, Tache* tache)
{
    EvenementTache* e = new EvenementTache(titre, pers, d, f, tache);
    ajouterEvenement(e);
    return e;
}

QString Agenda::genererNewId(){
    QString newId;
    do  { newId = randomString(5);
        } while (isExistant(newId));
    return newId;
}

QList<Evenement *> Agenda::getEvenements(const QDate &date)
{
    QList<Evenement*> liste;
    QDate dateDebutSemaine= date.addDays(1-date.dayOfWeek());
    QDate dateFinSemaine= dateDebutSemaine.addDays(6);
    for (QList<Evenement*>::iterator it = listeEvts.begin(); it!=listeEvts.end(); it++){
        if ( (*it)->getDateFin().date() >= dateDebutSemaine && (*it)->getDateDebut().date() <= dateFinSemaine)
            liste.push_back(*it);
    }
    return liste;
}

void Agenda::supprimerEvenement(Evenement* e){
    int i=0;
    QList<Evenement*>::Iterator it= listeEvts.begin();
    while((it != listeEvts.end()) && ((*it) != e)){
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


