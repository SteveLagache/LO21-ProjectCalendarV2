#include <QApplication>
#include <QMainWindow>
#include "agenda.h"
#include "projectcalendar.h"
#include "projetmanager.h"
#include "tachemanager.h"
#include "outils.h"
#include <QtDebug>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    TacheManager& tm = TacheManager::getInstance();
    TacheComposite* tc= tm.ajouterTacheComposite("test",QDate(2000,1,1), QDate(2010,1,1));
    TacheComposite* tc2= tm.ajouterTacheComposite("test2",QDate(2000,1,1), QDate(2010,1,1));
    TacheComposite* tc3= tm.ajouterTacheComposite("test3",QDate(2000,1,1), QDate(2010,1,1));
    Tache* tu= tm.ajouterTacheUnitaire("test",QDate(2000,1,1), QDate(2010,1,1), Duree(2,0), false);
    tc->ajouterSousTache(tc2);
    tc->ajouterSousTache(tu);
    tc->ajouterSousTache(tc3);

    QList<Tache*> liste= tu->getTachesPrecedentes();
    for(QList<Tache*>::const_iterator it = liste.begin(); it != liste.end(); it++)
        qDebug()<< (*it)->getTitre();

    QList<Tache*> liste2= tc3->getTachesPrecedentes();
    for(QList<Tache*>::const_iterator it = liste2.begin(); it != liste2.end(); it++)
        qDebug()<< (*it)->getTitre();


    ProjetManager& pm=ProjetManager::getInstance();
    Projet* p= pm.ajouterProjet("projet", QDate(2000,1,1), QDate(2010,1,1));
    p->ajouterTache(tc);
    qDebug() <<p->contientTache(tc)<< p->contientTache(tu);

    ProjectCalendar projectCalendar;
    projectCalendar.showMaximized();
    projectCalendar.show();

    return app.exec();
}
