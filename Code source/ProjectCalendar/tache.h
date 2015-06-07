#ifndef TACHE_H
#define TACHE_H

/*!
 * \file tache.h
 * \brief Taches des projets
 * \author Guyet-Lagache
 */

#include <QDate>
#include <QList>
#include "time.h"
//#include "tachemanager.h"


/**
 * \class Tache
 * \brief Tache
 *
 * Une tâche ne peut être associée qu’à un seul projet.
 * Une tâche (unitaire ou composite) est caractérisée par :
 *      un titre (permettant d’en saisir la nature)
 *      une date de disponibilité (date à laquelle on pourra commencer la tâche)
 *      une date d'écheance (date à laquelle la tâche doit être terminée.
 */
class Tache{
protected:
    friend class Projet;
    QString id;
    QString titre;
    QDate disponibilite;
    QDate echeance;

    Tache& operator=(const Tache&);
    Tache(const Tache& t);
    /**
    * \brief Constructeur de Tache
    * \param const QString& titre : titre de la tache,
    * const QDate& dispo : date de disponibilité de la tache,
    * const QDate& deadline : date d'échéance de la tache
    */
    Tache(const QString& titre, const QDate& dispo, const QDate& deadline);


public:

   // virtual ~Tache();
    virtual QString getType() const =0;

    QString getId() const {return id;};

    QString getTitre() const { return titre; }
    void setTitre(const QString& str) { titre=str; }

    QDate getDateDisponibilite() const { return disponibilite; }
    QDate getDateEcheance() const { return echeance; }

    /**
    * \brief Vérifie que (date dispo < date échéance) avant de les appliquer à la tache
    * \param const QDate& dispo : date de disponibilité de la tache,
    * const QDate& deadline : date d'échéance de la tache
    */
    void setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e);
};




/**
 * \class TacheComposite
 * \brief Tache composite qui contient des sous-taches
 *
 * TacheComposite hérite de la classe Tache.
 * Elle contient des sous-tâches (composites ou unitaires)
 */
class TacheComposite: public Tache{
private:

    QList<Tache*> sousTaches;
    // Liste chainée de pointeurs sur taches

public:
    QString getType() const override {return "TacheComposite";} ;

    QList<Tache*>& getSousTaches() {return sousTaches;};

    TacheComposite(const QString& t, const QDate& dispo, const QDate& deadline):
        Tache(t, dispo, deadline){}

   // ~TacheComposite();

    void afficherSousTaches();

    /**
    * \brief Ajoute une sous-tâche
    * \param Tache* t: pointeur sur la tâche à ajouter
    */
    void ajouterSousTache(Tache* t);
};




/**
 * \class TacheUnitaire
 * \brief Tache unitaire (non composite)
 *
 * TacheUnitaire hérite de la classe Tache.
 * De plus, une TacheUnitaire est définie par une durée.
 * Elle peut être préemptable ou non.
 */
class TacheUnitaire : public Tache{
private:
    Duree duree;
    bool preemptive;

public:
    QString getType() const override {return "TacheUnitaire";} ;
    TacheUnitaire(const QString& t, const QDate& dispo, const QDate& deadline,const Duree& duree, bool preempt):
        Tache(t, dispo, deadline), duree(duree), preemptive(preempt){}
   // ~TacheUnitaire();
    bool isPreemptive() const { return preemptive; }
    Duree getDuree() const {return duree;}
    void setDuree(const Duree& newDuree) {duree = newDuree;}
    void setPreemptive() { preemptive=true; }
    void setNonPreemptive() { preemptive=false; }

};




#endif // TACHE_H

