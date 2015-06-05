#ifndef PROJECTCALENDAR_H
#define PROJECTCALENDAR_H

#include "weekcalendar.h"
#include <QMainWindow>

namespace Ui {
class ProjectCalendar;
}

class ProjectCalendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProjectCalendar(QWidget *parent = 0);
    ~ProjectCalendar();

private:
    WeekCalendar* semaine;
    Ui::ProjectCalendar *ui;
};

#endif // PROJECTCALENDAR_H
