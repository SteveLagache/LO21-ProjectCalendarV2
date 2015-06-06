#include <QApplication>
#include <QMainWindow>
#include <QString>
#include <QDateTime>
#include "projectcalendar.h"
#include "evenement.h"

int main(int argc, char* argv[]) {
     QApplication app(argc, argv);




    ProjectCalendar projectCalendar;
    projectCalendar.show();


    return app.exec();
}
