#ifndef WEEKCALENDAR_H
#define WEEKCALENDAR_H

#include <QWidget>

/*!
 * \file weekcalendar.h
 * \brief Affichage graphique de l'agenda
 * \author Guyet-Lagache
 */

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
