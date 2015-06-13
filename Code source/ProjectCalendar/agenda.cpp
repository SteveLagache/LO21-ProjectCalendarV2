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
            if (listeEvts.size() == 0) //LISTE VIDE
                listeEvts.push_back(e);
            else if (listeEvts[0]->getDateDebut() > e->getDateFin()) //ON PLACE EN PREMIER
                listeEvts.insert(0, e);
            else {
                int i= 1; // CAR PREMIER TESTé
                QList<Evenement*>::Iterator it = listeEvts.begin();
                QList<Evenement*>::Iterator precedent = listeEvts.begin();
                it++;
                while ((it != listeEvts.end()) && ((*it)->getDateFin() < e->getDateDebut())) {
                    i++;
                    it++;
                    precedent++;
                }
                if (it == listeEvts.end()) // ON ARRIVE A LA FIN
                    if ((*precedent)->getDateFin() >= e->getDateDebut())
                        throw CalendarException("On ne peut pas progammer 2 évènements en même temps");
                    else listeEvts.push_back(e);
                else { // MILIEU
                    if ((*it)->getDateDebut() > e->getDateFin())
                        listeEvts.insert(i, e);
                    else
                        throw CalendarException("On ne peut pas programmer 2 évènements en même temps");
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
  try {
    if (tache->isProgrammable()) {
        if ((tache->getDateDisponibilite() < d.date()) && (tache->getDateEcheance() > f.date())) {
            Agenda& a = Agenda::getInstance();
            QList<Evenement*> evenements = a.getEvenements();
            for (QList<Evenement*>::const_iterator it = evenements.begin(); it!=evenements.end(); it++) {
                if ((*it)->getType()=="EvenementTache"){
                    EvenementTache* et= dynamic_cast<EvenementTache*>(*it);
                    QList<Tache*> preced = tache->getTachesPrecedentes();
                    for (QList<Tache*>::const_iterator it2 = preced.begin(); it2!=preced.end(); it2++) {
                        if (*it2 == et->getTache()) {
                             if (et->getDateFin() < d)
                                  ajouterEvenement(e);
                              else throw CalendarException("Doit être programmée après "+et->getTitre()+" : "+et->getId());
                        }
                    }
                }
           }
                ajouterEvenement(e);
        }
        else throw CalendarException("Contraintes de dispo et échéance non respectées");
   }
   else throw CalendarException("Tâche non programmable");
  }
    catch(CalendarException e){
        e.afficherWarning();
    }

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

/*
void  Agenda::save(const QString& f){
    QFile newfile(f);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw CalendarException(QString("Erreur sauvegarde évènements : ouverture fichier XML"));
    QXmlStreamWriter stream(&newfile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("evenements");
    for (QList<Evenement*>::Iterator it= listeEvts.begin(); it != listeEvts.end(); ++it){
        stream.writeStartElement("evenement");
        // stream.writeAttribute("preemptive", (taches[i]->isPreemptive())?"true":"false");
        stream.writeTextElement("identificateur", (*it)->getId());
        stream.writeTextElement("titre", (*it)->getTitre());
        stream.writeTextElement("debut", (*it)->getDateDebut().toString(Qt::ISODate));
        stream.writeTextElement("fin",(*it)->getDateFin().toString(Qt::ISODate));
        // QString str;
        // str.setNum(taches[i]->getDuree().getDureeEnMinutes());
        // stream.writeTextElement("duree",str);
        stream.writeEndElement();
    }
    stream.writeEndElement();
    stream.writeEndDocument();
    newfile.close();
}

*/
