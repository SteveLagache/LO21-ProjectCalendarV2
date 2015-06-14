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

    ///
    /// \brief charge les événements dans le calendrier
    /// \param date : date pour laquelle nous allons afficher le calendrier
    ///
    void chargerSemaine(const QDate date);

    ///
    /// \brief Retire les évènements affichés dans un Layout (une journée)
    /// \param layout : Layout (journée) à vider
    ///
    /// Appelé lors d'un changement de date courante
    ///
    void clearLayout(QLayout *layout);
private:
    Ui::WeekCalendar *ui;
    QDate dateDebutSemaine;


public slots:

    ///
    /// \brief Change la semaine courante (semaine suivante)
    ///
    void augmenterDate();

    ///
    /// \brief change la semaine courante (semaine précédente)
    ///
    void reduireDate();

    void updateDateLundi();
    void updateDateDimanche();

    ///
    /// \brief execute une fenetre de création d'une nouvelle activité
    ///
    void ajouterActivite();

    ///
    /// \brief execute une fenetre de programmation de tâche
    ///
    void programmerTache();

    ///
    /// \brief execute une fenetre d'exportation d'événements
    ///
    void lancerExport();

    ///
    /// \brief execute une fenetre d'étition d'événements
    ///
    void lancerListeEvenements();


};

#endif // WEEKCALENDAR_H
