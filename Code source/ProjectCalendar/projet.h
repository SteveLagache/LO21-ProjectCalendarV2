#ifndef PROJET_H
#define PROJET_H

/*!
 * \file projet.h
 * \brief Projets
 * \author Guyet-Lagache
 */

#include "tache.h"
#include "projetmanager.h"

class Tache;

/**
 * \class Projet
 * \brief Projet
 *
 * Un projet est caractérisé par :
 *      des tâches
 *      un titre (permettant d’en saisir la nature)
 *      une date de disponibilité (date à laquelle on pourra commencer le projet)
 *      une date d'écheance (date à laquelle le projet doit être terminé)
 * L’échéance d’un projet est une borne supérieure de l’ensemble des échéances des tâches de ce projet.
 *
 */
class Projet{
private:
    friend class ProjetManager;
    QList<Tache*> taches;
    QString titre;
    QDate disponibilite;
    QDate echeance;

    Projet(const QString& titre, const QDate& dispo, const QDate& deadline);
    ~Projet();

public:

    ///
    /// \brief Renvoie les tâches faisant partie du projet
    /// \return Liste de pointeurs sur tâches
    ///
    QList<Tache*>& getTaches() { return taches;}

    QString getTitre() const { return titre; }
    void setTitre(const QString& str);

    QDate getDateDisponibilite() const { return disponibilite; }
    QDate getDateEcheance() const { return echeance; }
    ///
    /// \brief Supprimer une tâche
    /// \param Tache* t : Pointeur sur la tâche à supprimer
    ///
    void supprimerTache(Tache*t);
    ///
    /// \brief Inverser la précédence avec la tâche se trouvant avant elle dans la liste des sous-tâches
    /// \param Tache* t : pointeur sur la tâche à inverser
    ///
    void monterPrecedence(Tache *t);
    ///
    /// \brief Inverser la précédence avec la tâche se trouvant après elle dans la liste des sous-tâches
    /// \param Tache* t : pointeur sur la tâche à inverser
    ///
    void descendrePrecedence(Tache *t);


    /**
    * \brief Vérifie que (date dispo < date échéance) avant de les appliquer au projet
    * \param const QDate& dispo : date de disponibilité du projet,
    * \param const QDate& deadline : date d'échéance du projet
    */
    void setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e);
    ///
    /// \brief Utilisée pour le développement
    ///
    void afficherTaches();

    /**
    * \brief Ajoute une tâche au projet
    * \param Tache* t: pointeur sur la tâche à ajouter.
    *
    */
    void ajouterTache(Tache* t);
    ///
    /// \brief Vérifie si le projet contient cette tâche
    /// \param Tache* t : pointeur sur la tâche à tester
    /// \return "true" si le projet contient la tâche, "false" sinon
    ///
    bool contientTache(Tache* t);

};

#endif // PROJET_H

