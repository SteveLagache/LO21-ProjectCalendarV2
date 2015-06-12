#include "weekcalendar.h"
#include "ui_weekcalendar.h"
#include <QtDebug>

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
