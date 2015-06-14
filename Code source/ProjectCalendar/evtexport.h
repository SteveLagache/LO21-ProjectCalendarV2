#ifndef EVTEXPORT_H
#define EVTEXPORT_H

#include <QDialog>
#include <QDate>

/*!
 * \file evtexport
 * \brief Fenetre d'exportation d'événements
 * \author Guyet-Lagache
 *
 * Permet l'exportation d'événement en fonction d'une semaine ou d'un projet
 */

namespace Ui {
class EvtExport;
}

class EvtExport : public QDialog
{
    Q_OBJECT

public:
    ///
    /// \brief Constructeur de EvtExport
    /// \param parent : Widget parent (=0 par défault)
    /// \param date : datecourante (=0 date du jour par défaut)
    ///
    explicit EvtExport(QWidget *parent = 0, QDate date = QDate::currentDate());
    ~EvtExport();

public slots:
    ///
    /// \brief Charge la liste des projets existants
    ///
    void chargerListe();

    ///
    /// \brief charge une date courante et modifie les DateEdit en fonction
    /// \param date : QDate , date à charger
    ///
    void chargerDate(QDate date);

    ///
    /// \brief augmente la date courante
    ///
    void augmenterDate();

    ///
    /// \brief reduit la date courante
    ///
    void reduireDate();

    ///
    /// \brief change la date du lundi selon la date courante
    ///
    void updateDateLundi();

    ///
    /// \brief change la date du dimanceh selon la date courante
    ///
    void updateDateDimanche();

    ///
    /// \brief permet l'export d'un projet seulement après selection d'un projet dans la liste
    ///
    void enableExport();

    ///
    /// \brief exportation de la semaine courante
    ///
    void exportSemaine();

    ///
    /// \brief exportation du projet sélectionné dans la liste
    ///
    void exportProjet();
private:
    Ui::EvtExport *ui;
    QDate dateDebutSemaine;
};

#endif // EVTEXPORT_H
