#include <QApplication>
#include <QMainWindow>
#include "agenda.h"
#include "projectcalendar.h"
#include "projetmanager.h"
#include "tachemanager.h"
#include "outils.h"
#include <QtDebug>
#include "evenementsimpleeditor.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);


///Chargement Initial
    ProjetManager& pm=ProjetManager::getInstance();
    Projet* p1= pm.ajouterProjet("Projet 1", QDate(2015,1,1), QDate(2016,1,1));
    Projet* p2= pm.ajouterProjet("Projet 2", QDate(2015,1,1), QDate(2016,1,1));

    TacheManager& tm = TacheManager::getInstance();
    TacheUnitaire* t1= tm.ajouterTacheUnitaire("Tâche 1", QDate(2015,1,1), QDate(2016,1,1), Duree(2,0), false);
    TacheUnitaire* t2= tm.ajouterTacheUnitaire("Tâche 2", QDate(2015,1,1), QDate(2016,1,1), Duree(3,0), true);
    TacheUnitaire* t3= tm.ajouterTacheUnitaire("Tâche 3", QDate(2015,1,1), QDate(2016,1,1), Duree(2,0), false);
    TacheUnitaire* t4= tm.ajouterTacheUnitaire("Tâche 4", QDate(2015,1,1), QDate(2016,1,1), Duree(1,0), false);
    TacheUnitaire* t5= tm.ajouterTacheUnitaire("Tâche 7", QDate(2015,1,1), QDate(2016,1,1), Duree(1,0), false);
    TacheUnitaire* t6= tm.ajouterTacheUnitaire("Tâche 8", QDate(2015,1,1), QDate(2016,1,1), Duree(1,0), true);
    TacheUnitaire* t7= tm.ajouterTacheUnitaire("Tâche 9", QDate(2015,1,1), QDate(2016,1,1), Duree(1,0), true);
    TacheUnitaire* t8= tm.ajouterTacheUnitaire("Tâche 10", QDate(2015,1,1), QDate(2016,1,1), Duree(1,0), false);
    TacheComposite* tc1= tm.ajouterTacheComposite("Tâche 5", QDate(2015,1,1), QDate(2016,1,1));
    TacheComposite* tc2= tm.ajouterTacheComposite("Tâche 6", QDate(2015,1,1), QDate(2016,1,1));

    p1->ajouterTache(t1);
    p1->ajouterTache(tc1);
    tc1->ajouterSousTache(t2);
    tc1->ajouterSousTache(tc2);
    tc2->ajouterSousTache(t3);
    tc2->ajouterSousTache(t5);

    p2->ajouterTache(t4);
    p2->ajouterTache(t6);
    p2->ajouterTache(t7);
    p2->ajouterTache(t8);

    Agenda& a = Agenda::getInstance();
    a.ajouterEvenementSimple("Evenement 1","",QDateTime(QDate::currentDate(),QTime(2,0)),QDateTime(QDate::currentDate(),QTime(4,0)),"ok");
    a.ajouterEvenementSimple("Evenement 2","",QDateTime(QDate::currentDate().addDays(-3),QTime(2,0)),QDateTime(QDate::currentDate().addDays(-3),QTime(5,0)),"ok");
    a.ajouterEvenementSimple("Evenement 3","",QDateTime(QDate::currentDate().addDays(8),QTime(2,0)),QDateTime(QDate::currentDate().addDays(8),QTime(4,0)),"ok");
    a.ajouterEvenementTache(t1->getTitre(), "", QDateTime(QDate::currentDate(), QTime(12, 0)), QDateTime(QDate::currentDate(), QTime(13, 0)), t1);


    ProjectCalendar projectCalendar;
    projectCalendar.showMaximized();
    projectCalendar.show();

    return app.exec();
}
