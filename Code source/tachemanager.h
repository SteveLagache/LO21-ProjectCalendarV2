#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H
#include "tache.h"

/*!
 * \file tachemanager.h
 * \brief TacheManager permettant de référencer toutes les tâches créées et donc d'éviter les doublons
 * \author Guyet-Lagache
 */

/**
 * \class TacheManager
 * \brief Conteneur des Taches
 *
 * TacheManager est un singleton.
 * Toutes les taches sont stockées dans l'instance de TacheManager, à leur création
 */
class TacheManager{
private:
    QVector<Tache*> taches;
    static TacheManager* instance;
    TacheManager();

public:
    ///
    /// \brief Ajoute une tâche composite
    /// \param const QString& titre : titre de la tâche
    /// \param QDate debut : disponibilité de la tâche
    /// \param QDate fin : échéance de la tâche
    /// \return Pointeur sur la tâche composite ajoutée
    ///
    TacheComposite* ajouterTacheComposite(const QString& titre, QDate debut, QDate fin);
    ///
    /// \brief Renvoie toutes les tâches
    /// \return Liste de pointeurs sur tâches
    ///
    const QVector<Tache*>& getTaches() const {return taches;}
    ///
    /// \brief Ajoute une tâche unitaire
    /// \param const QString& titre : titre de la tâche,
    /// \param QDate debut : disponibilité de la tâche,
    /// \param QDate fin : échéance de la tâche,
    /// \param Duree duree : durée de la tâche,
    /// \param bool preemp :préemptivité de la tâche
    /// \return pointeur sur la tâche unitaire ajoutée
    ///
    TacheUnitaire* ajouterTacheUnitaire(const QString& titre, QDate debut, QDate fin, Duree duree, bool preemp);
    ///
    /// \brief Ajoute une tâche
    /// \param Tache* t : pointeur sur la tâche à ajouter
    ///
    void ajouterTache(Tache* t);
    ///
    /// \brief Supprimer une tâche
    /// \param const QString& id : id de la tâche à supprimer
    ///
    void supprimerTache(const QString& id);
    ///
    /// \brief Supprimer une tâche
    /// \param Tache* t : pointeur sur la tâche à supprimer
    ///
    void supprimerTache(Tache* t);
    static TacheManager& getInstance();
    ///
    /// \brief Remplace une tâche par une autre
    /// \param Tache* t : pointeur sur la tâche à remplacer
    /// \param Tache* t2 : pointeur sur la tâche qui remplace
    /// \return pointeur sur la nouvelle tâche
    ///
    Tache *remplacerTache(Tache* t, Tache* t2);

    /**
    * \brief Génère une nouvelle clef unique
    * \return chaîne de caractère créée aléatoirement, de longueur 5
    */
    QString genererNewId();

    bool isExistant(QString id);
    bool isExistant(Tache* t);
    ///
    /// \brief Recherche une tâche
    /// \param QString id : id de la tâche à chercher
    /// \return Pointeur sur la tâche trouvée
    ///
    Tache* trouverTache(QString id);
    ///
    /// \brief Affiche les tâches,utilisée pour le développement
    ///
    void afficherTaches();

};



#endif // TACHEMANAGER_H

