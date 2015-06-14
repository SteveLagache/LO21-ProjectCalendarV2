#ifndef PROJECTCALENDAR_H
#define PROJECTCALENDAR_H

#include "weekcalendar.h"
#include <QMainWindow>
#include <QTreeWidget>
#include "projetmanager.h"
#include "tachemanager.h"
#include <QList>
#include "tacheeditor.h"

#include "projeteditor.h"

/*!
 * \file projectcalendar.h
 * \brief Fenêtre principale du programme
 * \author Guyet-Lagache
 */



namespace Ui {
class ProjectCalendar;
}

/**
 * \class ProjectCalendar
 * \brief Fenêtre principale du programme
 */
class ProjectCalendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProjectCalendar(QWidget *parent = 0);
    ~ProjectCalendar();

    ///
    /// \brief charge l'arbre des Projets/taches
    /// \param arbre : arbre à charger
    ///
    void chargerArbre(QTreeWidget* arbre);

    ///
    /// \brief charger les tâches contenues dans le projet
    /// \param projetItem : racine de l'arbre à charger
    /// \param projet : projet à charger
    ///
    void chargerTaches(QTreeWidgetItem* projetItem, Projet* projet);

    ///
    /// \brief charger les tâches contenues dans une tache composite
    /// \param projetItem :  racine de l'arbre à charger
    /// \param tache : tacheComposite à charger
    ///
    void chargerTaches(QTreeWidgetItem* projetItem, TacheComposite *tache);

    ///
    /// \brief Modification d'une tâche
    ///
    /// Fonction appelée si l'élément que l'on veut modifier est une tâche. Elle executera une fenêtre de modification.
    ///
    void modifierTache();

    ///
    /// \brief Modification d'un projet
    ///
    /// Fonction appelée si l'élement que l'on veut modifier est un projet. Elle executera une fenêtre de modification.
    ///
    void modifierProjet();

private:
    WeekCalendar* calendrierSemaine;
    Ui::ProjectCalendar *ui;

public slots:
    ///
    /// \brief Active le bouton AjouterTache après selection d'un item dans l'arbre
    ///
    void enableAjouterTache();

    ///
    /// \brief Active le bouton Supprimer après selection d'un item dans l'arbre
    ///
    void enableSupprimer();

    ///
    /// \brief Active le bouton Modifier après selection d'un item dans l'arbre
    ///
    void modifierElement();

    ///
    /// \brief execute une fenêtre de création de projet
    ///
    void ajouterProjet();

    ///
    /// \brief execute une fenetre de création de tâche
    ///
    void ajouterTache();

    ///
    /// \brief Supprime l'élément selectionné
    ///
    void supprimerElement();

    ///
    /// \brief Monte la tâche dans les précédences
    ///
    ///
    void monterTache();

    ///
    /// \brief Descend la tâche dans les précédences
    ///
    void descendreTache();

    ///
    /// \brief Active ou désactive les flèches si la tâche peut changer son rang de précédence
    ///
    void enableFleches();

    ///
    /// \brief Active le bouton ProgrammerTache si la tâche est programmable
    ///
    void enableProgrammer();


    ///
    /// \brief lance une fenetre de programmation de tâche
    ///
    void programmerTache();


};


#endif // PROJECTCALENDAR_H
