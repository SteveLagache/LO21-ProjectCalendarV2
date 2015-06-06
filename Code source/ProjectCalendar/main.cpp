#include <QApplication>
#include <QMainWindow>
#include "projectcalendar.h"
#include "projet.h"
#include "agenda.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);


    TacheUnitaire t("test1", QDate(2010, 6,1), QDate(2011, 6,10), Duree(2, 0), false);

    TacheUnitaire t("test1", QDate(2010, 6,1), QDate(2025, 6,10), Duree(2, 0), false);

    TacheUnitaire t2("test2", QDate(2010, 6,1), QDate(2009, 6,10), Duree(2), true);
    TacheComposite t3("test3", QDate(2010, 6,1), QDate(2022, 6,10));

    Projet p("Projet1", QDate(2000,6,1), QDate(2015, 2, 3));

    t3.ajouterSousTache(&t);
    t3.ajouterSousTache(&t2);


    t3.afficherSousTaches();

    // EvenementSimple e("titre", "Steve", QDateTime(QDate(2013, 5, 28)), QDateTime(QDate(2012, 5, 29)), "Ruche");
    // e.setDatesDebutFin(QDateTime(QDate(2014, 5, 28)), QDateTime(QDate(2013, 5, 29)));

   // t3.afficherSousTaches();


    p.ajouterTache(&t);
    p.ajouterTache(&t3);
    p.afficherTaches();


    ProjectCalendar projectCalendar;
    projectCalendar.show();

    return app.exec();
}
