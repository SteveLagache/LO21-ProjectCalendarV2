#include <QApplication>
#include <QMainWindow>
#include "projectcalendar.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);




    ProjectCalendar projectCalendar;
    projectCalendar.show();

    return app.exec();
}
