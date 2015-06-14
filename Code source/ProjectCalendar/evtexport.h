#ifndef EVTEXPORT_H
#define EVTEXPORT_H

#include <QDialog>
#include <QDate>

namespace Ui {
class EvtExport;
}

class EvtExport : public QDialog
{
    Q_OBJECT

public:
    explicit EvtExport(QWidget *parent = 0, QDate date = QDate::currentDate());
    ~EvtExport();

public slots:
    void chargerListe();
    void chargerDate(QDate date);
    void augmenterDate();
    void reduireDate();
    void updateDateLundi();
    void updateDateDimanche();
    void enableExport();
    void exportSemaine();
    void exportProjet();
private:
    Ui::EvtExport *ui;
    QDate dateDebutSemaine;
};

#endif // EVTEXPORT_H
