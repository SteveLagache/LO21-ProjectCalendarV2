#include <QApplication>
#include <QMainWindow>
#include "projectcalendar.h"
#include "projet.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    TacheUnitaire t("test1", QDate(2010, 6,1), QDate(2011, 6,10), Duree(2, 0), false);
    TacheUnitaire t2("test2", QDate(2010, 6,1), QDate(2009, 6,10), Duree(2), true);
    TacheComposite t3("test2", QDate(2010, 6,1), QDate(2014, 6,10));

    t3.ajouterSousTache(&t);
    t3.ajouterSousTache(&t2);

    t3.afficherSousTaches();

    ProjectCalendar projectCalendar;
    projectCalendar.show();

    return app.exec();
}
