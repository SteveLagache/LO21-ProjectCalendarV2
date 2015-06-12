#include "weekcalendar.h"
#include "ui_weekcalendar.h"
#include <QtDebug>
#include  "evenementsimpleeditor.h"
#include  "evenementtacheeditor.h"
#include "tacheprogrammeur.h"

WeekCalendar::WeekCalendar(QWidget *parent, QDate date) :
    QWidget(parent),
    ui(new Ui::WeekCalendar)
{
    ui->setupUi(this);

    dateDebutSemaine= date.addDays(1-date.dayOfWeek());
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
    qDebug() << dateDebutSemaine;
    //chargerSemaine(dateDebutSemaine);


    QObject::connect(ui->dateDimanche, SIGNAL(dateChanged(QDate)), this, SLOT(updateDateDimanche()));
    QObject::connect(ui->dateLundi, SIGNAL(dateChanged(QDate)), this, SLOT(updateDateLundi()));
    QObject::connect(ui->flecheGauche, SIGNAL(clicked()), this, SLOT(reduireDate()));
    QObject::connect(ui->flecheDroite, SIGNAL(clicked()), this, SLOT(augmenterDate()));
    QObject::connect(ui->buttonProgrammerActivite, SIGNAL(clicked()), this, SLOT(ajouterActivite()));
    QObject::connect(ui->buttonProgrammerTache, SIGNAL(clicked()), this, SLOT(programmerTache()));
}

WeekCalendar::~WeekCalendar()
{
    delete ui;
}



void WeekCalendar::updateDateLundi()
{
    dateDebutSemaine = ui->dateLundi->date().addDays(1- ui->dateLundi->date().dayOfWeek());
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
    //chargerSemaine(dateDebutSemaine);
}

void WeekCalendar::updateDateDimanche()
{
    dateDebutSemaine = ui->dateDimanche->date().addDays(1- ui->dateLundi->date().dayOfWeek());
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
    //chargerSemaine(dateDebutSemaine);

}

void WeekCalendar::ajouterActivite()
{
    EvenementSimpleEditor ese(0,0);
    ese.exec();
}

void WeekCalendar::programmerTache()
{
    TacheProgrammeur tp;
    tp.exec();
}

void WeekCalendar::augmenterDate(){
    dateDebutSemaine = dateDebutSemaine.addDays(7);
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
    //chargerSemaine(dateDebutSemaine);

}

void WeekCalendar::reduireDate(){
    dateDebutSemaine = dateDebutSemaine.addDays(-7);
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
    //chargerSemaine(dateDebutSemaine);

}
