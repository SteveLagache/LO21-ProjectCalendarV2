#include <QApplication>
#include <QMainWindow>
#include "agenda.h"
#include "projectcalendar.h"
#include "projetmanager.h"
#include "tachemanager.h"
#include "outils.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);


    ProjectCalendar projectCalendar;
    projectCalendar.show();

    return app.exec();
}
