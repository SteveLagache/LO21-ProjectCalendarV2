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
    void chargerArbre(QTreeWidget* arbre);
    void chargerTaches(QTreeWidgetItem* projetItem, Projet* projet);
    void chargerTaches(QTreeWidgetItem* projetItem, TacheComposite *tache);
    void modifierTache();
    void modifierProjet();

private:
    WeekCalendar* calendrierSemaine;
    Ui::ProjectCalendar *ui;

public slots:

      void enableAjouterTache();
      void enableSupprimer();
      void modifierElement();
      void ajouterProjet();
      void ajouterTache();
      void supprimerElement();
      void monterTache();
      void descendreTache();
      void disablePourProjet();


};


#endif // PROJECTCALENDAR_H
