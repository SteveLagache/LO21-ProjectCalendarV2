#ifndef PROJECTCALENDAR_H
#define PROJECTCALENDAR_H

#include "weekcalendar.h"
#include <QMainWindow>
#include <QTreeWidget>
#include "projetmanager.h"

/*!
 * \file projectcalendar.h
 * \brief Fenêtre principale du programme
 * \author Guyet-Lagache
 */

namespace Ui {
class ProjectCalendar;
}

class ProjectCalendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProjectCalendar(QWidget *parent = 0);
    ~ProjectCalendar();
    void chargerArbre(QTreeWidget* arbre);
    void chargerTaches(QTreeWidgetItem* projetItem, Projet* projet);
    void chargerTaches(QTreeWidgetItem* projetItem, TacheComposite *tache);

private:
    WeekCalendar* calendrierSemaine;
    Ui::ProjectCalendar *ui;
};

#endif // PROJECTCALENDAR_H
