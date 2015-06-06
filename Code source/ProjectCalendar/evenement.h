#ifndef EVENEMENT
#define EVENEMENT

#include <QString>
#include <QDateTime>
#include "exception.h"

/*!
 * \file evenement.h
 * \brief Evènements
 * \author Guyet-Lagache
 */

class Evenement {
protected :
    QString titre;
    QString personnes;
    QDateTime debut;
    QDateTime fin;
    Evenement(const QString& t, const QString& pers, const QDateTime& d, const QDateTime& f):
        titre(t), personnes(pers), debut(d), fin(f){}
    virtual ~Evenement() {}
    // friend Agenda;
public :
    QString getTitre() const { return titre; }
    void setTitre(const QString& str) { titre=str; }
    QString getPersonnes() const { return personnes; }
    void setPersonnes(const QString& p) { personnes=p; }
    QDateTime getDateDebut() const {  return debut; }
    QDateTime getDateFin() const {  return fin; }
    void setDatesDebutFin(const QDateTime& d, const QDateTime& f) {
        if (f<d) throw CalendarException("erreur Tâche : date fin < date début");
         debut=d; fin=f;
    }
};

class EvenementSimple : public Evenement {
    QString lieu;
public :
    EvenementSimple(const QString& t, const QString& pers, const QDateTime& d, const QDateTime& f, const QString& l):
        Evenement(t, pers, d, f), lieu(l){}
    ~EvenementSimple() {}
    QString getLieu() const { return lieu; }
    void setLieu(const QString& l) { lieu=l; }
};

class EvenementTache : public Evenement {
public :
    EvenementTache(const QString& t, const QString& pers, const QDateTime& d, const QDateTime& f) :
        Evenement(t, pers, d, f) {}
    ~EvenementTache(){}
};




#endif // EVENEMENT

