#include "evtexport.h"
#include "ui_evtexport.h"
#include "agenda.h"
#include "projetmanager.h"

EvtExport::EvtExport(QWidget *parent, QDate date) :
    QDialog(parent),
    ui(new Ui::EvtExport)
{
    ui->setupUi(this);
    chargerListe();

    dateDebutSemaine= date.addDays(1-date.dayOfWeek());

    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));

    QObject::connect(ui->buttonExportProjet, SIGNAL(clicked()), this, SLOT(exportProjet()));
    QObject::connect(ui->buttonExportSemaine, SIGNAL(clicked()), this, SLOT(exportSemaine()));

    QObject::connect(ui->dateLundi, SIGNAL(dateChanged(QDate)), this, SLOT(updateDateLundi()));
    QObject::connect(ui->dateDimanche, SIGNAL(dateChanged(QDate)), this, SLOT(updateDateDimanche()));
    QObject::connect(ui->flecheGauche, SIGNAL(clicked()), this, SLOT(reduireDate()));
    QObject::connect(ui->flecheDroite, SIGNAL(clicked()), this, SLOT(augmenterDate()));
    QObject::connect(ui->listWidgetProjets, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(enableExport()));
    QObject::connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(chargerListe()));

}

EvtExport::~EvtExport()
{
    delete ui;
}


//////////SLOTS



void EvtExport::chargerListe(){
    ui->buttonExportProjet->setEnabled(false);
    ui->listWidgetProjets->clear();
    ProjetManager& pm = ProjetManager::getInstance();
    QVector<Projet*> listeProjets= pm.getProjets();
    for (QVector<Projet*>::const_iterator it = listeProjets.begin(); it!= listeProjets.end(); it++){
        QListWidgetItem * item = new QListWidgetItem((*it)->getTitre());
        ui->listWidgetProjets->addItem(item);
    }
}

void EvtExport::chargerDate(QDate date)
{
    dateDebutSemaine = date.addDays(1-date.dayOfWeek());
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
};


void EvtExport::augmenterDate(){
    chargerDate(dateDebutSemaine.addDays(7));
}

void EvtExport::reduireDate(){
    chargerDate(dateDebutSemaine.addDays(-7));

}



void EvtExport::updateDateLundi()
{
    dateDebutSemaine = ui->dateLundi->date().addDays(1- ui->dateLundi->date().dayOfWeek());
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
}

void EvtExport::updateDateDimanche()
{
    dateDebutSemaine = ui->dateDimanche->date().addDays(1- ui->dateDimanche->date().dayOfWeek());
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
}

void EvtExport::exportSemaine(){
    Agenda& a = Agenda::getInstance();
    a.export_semaine(dateDebutSemaine);

}

void EvtExport::exportProjet(){
    QListWidgetItem* item =ui->listWidgetProjets->selectedItems()[0];
    ProjetManager& pm = ProjetManager::getInstance();
    QString str = item->text();
    Projet* p= pm.trouverProjet(str);

    Agenda& a = Agenda::getInstance();
    a.export_projet(p);

}


void EvtExport::enableExport(){
    ui->buttonExportProjet->setEnabled(true);
}
