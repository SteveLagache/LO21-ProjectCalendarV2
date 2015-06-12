#include "agenda.h"


Evenement::Evenement(const QString& t, const QString& pers, const QDateTime& d, const QDateTime& f) {
    Agenda a = Agenda::getInstance();
    id = a.genererNewId();
    titre = t;
    personnes = pers;
    setDatesDebutFin(d, f);
}


void Evenement::setDatesDebutFin(const QDateTime& d, const QDateTime& f) {
    debut = d;
    if (f <= d)
    {
        fin = debut.addSecs(3600);
        try {
            throw CalendarException("Problème dans les dates de lévènement:\n( date fin < date début)\n La date de fin a été modifiée : début + 1h");
        }
        catch(CalendarException e){
            e.afficherWarning();
        }
    }
    else fin = f;

}
