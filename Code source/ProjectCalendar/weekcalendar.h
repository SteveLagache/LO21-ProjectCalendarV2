#ifndef WEEKCALENDAR_H
#define WEEKCALENDAR_H

#include <QWidget>
#include <QDate>

/*!
 * \file weekcalendar.h
 * \brief Affichage graphique de l'agenda
 * \author Guyet-Lagache
 */

namespace Ui {
class WeekCalendar;
}



/**
 * \class WeekCalendar
 * \brief Widget pour afficher la partie Agenda
 */
class WeekCalendar : public QWidget
{
    Q_OBJECT

public:
    explicit WeekCalendar(QWidget *parent = 0, QDate date = QDate::currentDate());
    ~WeekCalendar();


    void chargerSemaine(const QDate date);
    void clearLayout(QLayout *layout);
private:
    Ui::WeekCalendar *ui;
    QDate dateDebutSemaine;


public slots:

    void augmenterDate();
    void reduireDate();
    void updateDateLundi();
    void updateDateDimanche();
    void ajouterActivite();
    void programmerTache();
    void lancerExport();
    void lancerListeEvenements();
};

#endif // WEEKCALENDAR_H
