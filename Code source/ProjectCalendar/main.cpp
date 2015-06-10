#include <QApplication>
#include <QMainWindow>
#include "agenda.h"
#include "projectcalendar.h"
#include "projetmanager.h"
#include "tachemanager.h"
#include "outils.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);


     TacheUnitaire t("test1", QDate(2010, 6,1), QDate(2025, 6,10), Duree(2, 0), false);
    TacheUnitaire t2("test2", QDate(2010, 6,1), QDate(2009, 6,10), Duree(2), true);
    TacheComposite t3("test3", QDate(2010, 6,1), QDate(2022, 6,10));

    Projet p("Projet1", QDate(2000,6,1), QDate(2015, 2, 3));

    t3.ajouterSousTache(&t);
    t3.ajouterSousTache(&t2);

   // t3.afficherSousTaches();


    p.ajouterTache(&t);
    p.ajouterTache(&t3);
    p.afficherTaches();

    ProjetManager& pm= ProjetManager::getInstance();
    pm.afficherProjets();
    pm.afficherProjets();

    /* EvenementSimple e1("t1", "Steve", QDateTime(QDate(2012, 5, 28)), QDateTime(QDate(2012, 5, 29)), "Ruche");
    EvenementSimple e2("t2", "Flo", QDateTime(QDate(2011, 5, 28)), QDateTime(QDate(2011, 5, 29)), "Mare");

    Agenda& a = Agenda::getInstance();
    a.ajouterEvenement(&e1);
    a.ajouterEvenement(&e2);
    a.afficherListeEvts();
    a.supprimerEvenement("t1");
    a.supprimerEvenement("ttt");
    a.afficherListeEvts(); */
    TacheManager& tm= TacheManager::getInstance();
    tm.afficherTaches();

    ProjectCalendar projectCalendar;
    projectCalendar.show();

    return app.exec();
}
