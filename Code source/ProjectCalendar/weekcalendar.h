#ifndef WEEKCALENDAR_H
#define WEEKCALENDAR_H

#include <QWidget>

namespace Ui {
class WeekCalendar;
}

class WeekCalendar : public QWidget
{
    Q_OBJECT

public:
    explicit WeekCalendar(QWidget *parent = 0);
    ~WeekCalendar();

private:
    Ui::WeekCalendar *ui;
};

#endif // WEEKCALENDAR_H
