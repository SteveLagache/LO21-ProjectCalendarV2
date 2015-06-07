#ifndef EVENEMENT
#define EVENEMENT

#include <QString>
#include <QDateTime>
#include "exception.h"
#include "projetmanager.h"

/*!
 * \file evenement.h
 * \brief Evénements
 * \author Guyet-Lagache
 */


/**
 * \class Evenement
 * \brief Evenement
 *
 * Un évènement est soit :
 *      - la programmation d’une activité traditionnelle
 *      - la programmation d’une tâche (unitaire) liée à un projet
 * Il n'est pas possible de programmer deux évènements en même temps
 * Interdiction : d’une programmation qui ne respecte pas l’ensemble des
 * contraintes liées à la tâche (contraintes de disponibilité, d’échéance, de précédence)
 */
class Evenement {
protected :
    QString titre;
    QString personnes;
    QDateTime debut;
    QDateTime fin;
    /**
    * \brief Constructeur d'Evenement
    * \param const QString& t : titre de l'évènement,
    * \param const QString& pers : personnes participant à l'évènement,
    * \param const QDateTime& d : date et heure de début de l'évènement,
    * \param const QDateTime& f : date et heure de fin de l'évènement
    */
    Evenement(const QString& t, const QString& pers, const QDateTime& d, const QDateTime& f);
    virtual ~Evenement() {}
    friend class Agenda;
public :
    QString getTitre() const { return titre; }
    void setTitre(const QString& str) { titre=str; }
    QString getPersonnes() const { return personnes; }
    void setPersonnes(const QString& p) { personnes=p; }
    QDateTime getDateDebut() const {  return debut; }
    QDateTime getDateFin() const {  return fin; }
    /**
    * \brief Vérifie que (date début < date fin) avant de les appliquer à l'évènement
    * \param const QDateTime& d : date et heure de début de l'évènement,
    * const QDateTime& f : date et heure de fin de l'évènement
    */
    void setDatesDebutFin(const QDateTime& d, const QDateTime& f);
    virtual QString getType() const =0;
};

/**
 * \class EvenementSimple
 * \brief EvenementSimple
 *
 * Programmation d’une activité traditionnelle
 * Ex: rendezvous, réunion
 */
class EvenementSimple : public Evenement {
    QString lieu;
public :
    /**
    * \brief Constructeur d'EvenementSimple
    * \param const QString& t : titre de l'évènement,
    * const QString& pers : personnes participant à l'évènement,
    * const QDateTime& d : date et heure de début de l'évènement,
    * const QDateTime& f : date et heure de fin de l'évènement,
    * const QString& l : lieu de l'évènement
    */
    EvenementSimple(const QString& t, const QString& pers, const QDateTime& d, const QDateTime& f, const QString& l):
        Evenement(t, pers, d, f), lieu(l){}
    ~EvenementSimple() {}
    QString getLieu() const { return lieu; }
    void setLieu(const QString& l) { lieu=l; }
    QString getType() const {return "EvenementSimple";}
};

/**
 * \class EvenementTache
 * \brief EvenementTache
 * La programmation d’une tâche (unitaire) liée à un projet ;
 * Si c'est une tâche unitaire qui peut être préemptée,
 * elle peut aussi être la programmation d’une partie seulement
 * (l’autre partie restant à être programmée plus tard)
 */
class EvenementTache : public Evenement {
private :
   QString idTache;
public :
    // EvenementTache(const QString& t, const QString& pers, const QDateTime& d, const QDateTime& f, const QString id) :
    //  Evenement(t, pers, d, f), idTache(id) {}
   /**
   * \brief Constructeur d'EvenementTache
   * \param const QString& pers : personnes participant à l'évènement,
   * const QDateTime& d : date et heure de début de l'évènement,
   * const QDateTime& f : date et heure de fin de l'évènement,
   * Tache* t : Tâche à programmer (contenant titre et id)
   */
    EvenementTache(const QString& pers, const QDateTime& d, const QDateTime& f, Tache* t) :
       Evenement(t->getTitre(), pers, d, f) {
        idTache=t->getId();
    }
    QString getIdTache() const { return idTache; }
    ~EvenementTache(){}
    QString getType() const {return "EvenementTache";}
};




#endif // EVENEMENT

