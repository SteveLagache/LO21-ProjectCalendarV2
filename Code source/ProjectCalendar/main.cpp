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
    TacheComposite* tc1= tm.ajouterTacheComposite("Tâche 5", QDate(2015,1,1), QDate(2016,1,1));
    TacheComposite* tc2= tm.ajouterTacheComposite("Tâche 6", QDate(2015,1,1), QDate(2016,1,1));

    p1->ajouterTache(t1);
    p1->ajouterTache(tc1);
    tc1->ajouterSousTache(t2);
    tc1->ajouterSousTache(tc2);
    tc2->ajouterSousTache(t3);
    tc2->ajouterSousTache(t5);
    p2->ajouterTache(t4);

    Agenda& a = Agenda::getInstance();
<<<<<<< HEAD
    a.ajouterEvenementSimple("e1","",QDateTime(QDate::currentDate().addDays(-5),QTime(2,0)),QDateTime(QDate::currentDate().addDays(3),QTime(2,0)),"ok");
    a.ajouterEvenementSimple("e2","",QDateTime(QDate::currentDate().addDays(-3),QTime(2,0)),QDateTime(QDate::currentDate().addDays(-3),QTime(5,0)),"ok");
    a.ajouterEvenementSimple("e3","",QDateTime(QDate::currentDate().addDays(8),QTime(2,0)),QDateTime(QDate::currentDate().addDays(8),QTime(4,0)),"ok");
=======
    a.ajouterEvenementSimple("e1","",QDateTime(QDate::currentDate(),QTime(2,0)),QDateTime(QDate::currentDate().addDays(3),QTime(2,0)),"ok");
    a.ajouterEvenementSimple("e2","",QDateTime(QDate::currentDate().addDays(-5),QTime(2,0)),QDateTime(QDate::currentDate().addDays(3),QTime(5,0)),"ok");
    a.ajouterEvenementSimple("e3","",QDateTime(QDate::currentDate().addDays(-3),QTime(2,0)),QDateTime(QDate::currentDate().addDays(-3),QTime(4,0)),"ok");
    a.ajouterEvenementTache("e4", "", QDateTime(QDate::currentDate().addDays(9), QTime(12, 0)), QDateTime(QDate::currentDate().addDays(10), QTime(12, 0)), t1);
    a.afficherListeEvts();
    QList<Evenement*> liste = a.getEvenements(QDate::currentDate());
    for (QList<Evenement*>::const_iterator it =liste.begin();it!=liste.end(); it++){
        if ((*it)->getType()=="EvenementSimple"){
            EvenementSimple* es= dynamic_cast<EvenementSimple*> (*it);
            EvenementSimpleEditor ese(0,es);
            ese.exec();
        }
        else {
//            EvenementTacheEditor ese(0,(*it));
//            ese.exec();
        }
    }

>>>>>>> origin/master


    ProjectCalendar projectCalendar;
    projectCalendar.showMaximized();
    projectCalendar.show();

    return app.exec();
}
