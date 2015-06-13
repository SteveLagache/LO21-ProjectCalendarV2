#include "weekcalendar.h"
#include "ui_weekcalendar.h"
#include <QtDebug>
#include  "evenementsimpleeditor.h"
#include  "evenementtacheeditor.h"
#include "tacheprogrammeur.h"
#include "evenementeditor.h"

WeekCalendar::WeekCalendar(QWidget *parent, QDate date) :
    QWidget(parent),
    ui(new Ui::WeekCalendar)
{
    ui->setupUi(this);

    dateDebutSemaine= date.addDays(1-date.dayOfWeek());
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
    qDebug() << dateDebutSemaine;
    chargerSemaine(dateDebutSemaine);

    ui->lundi->setAlignment(Qt::AlignTop);
    ui->mardi->setAlignment(Qt::AlignTop);
    ui->mercredi->setAlignment(Qt::AlignTop);
    ui->jeudi->setAlignment(Qt::AlignTop);
    ui->vendredi->setAlignment(Qt::AlignTop);
    ui->samedi->setAlignment(Qt::AlignTop);
    ui->dimanche->setAlignment(Qt::AlignTop);

    QObject::connect(ui->dateDimanche, SIGNAL(dateChanged(QDate)), this, SLOT(updateDateDimanche()));
    QObject::connect(ui->dateLundi, SIGNAL(dateChanged(QDate)), this, SLOT(updateDateLundi()));
    QObject::connect(ui->flecheGauche, SIGNAL(clicked()), this, SLOT(reduireDate()));
    QObject::connect(ui->flecheDroite, SIGNAL(clicked()), this, SLOT(augmenterDate()));
    QObject::connect(ui->buttonProgrammerActivite, SIGNAL(clicked()), this, SLOT(ajouterActivite()));
    QObject::connect(ui->buttonProgrammerTache, SIGNAL(clicked()), this, SLOT(programmerTache()));
    QObject::connect(ui->buttonModifier, SIGNAL(clicked()), this, SLOT(lancerListeEvenements()));
    QObject::connect(ui->buttonExporter, SIGNAL(clicked()), this, SLOT(lancerExport()));
}

WeekCalendar::~WeekCalendar()
{
    delete ui;
}


void WeekCalendar::clearLayout(QLayout *layout)
{
    if (layout) {
        while(layout->count() > 0){
            QLayoutItem *item = layout->takeAt(0);
            delete item->widget();
            delete item;
        }
    }
}

void WeekCalendar::chargerSemaine(const QDate date){

    clearLayout(ui->lundi);
    clearLayout(ui->mardi);    
    clearLayout(ui->mercredi);
    clearLayout(ui->jeudi);
    clearLayout(ui->vendredi);
    clearLayout(ui->samedi);  
    clearLayout(ui->dimanche);

    Agenda& a = Agenda::getInstance();
    QList<Evenement*> liste = a.getEvenements(date);
    for( QList<Evenement*>::const_iterator it = liste.begin(); it != liste.end(); it++){

        //setTaille
        //setPosition

        QDate debut=(*it)->getDateDebut().date();
        QDate fin=(*it)->getDateFin().date();

        QDate dateFinSemaine = dateDebutSemaine.addDays(6);

        int i= debut.dayOfWeek();
        int imax= fin.dayOfWeek();

        if (debut < dateDebutSemaine)
            i=1;
        if (fin > dateFinSemaine)
            imax=7;

        while (i <= imax){

            QString buttonName((*it)->getTitre()+
                               "\n\nde "+(*it)->getDateDebut().date().toString()+
                               "\n"+(*it)->getDateDebut().time().toString()+
                               "\nà " + (*it)->getDateFin().date().toString() +
                               "\n"+(*it)->getDateFin().time().toString());
            QPushButton *button = new QPushButton;
            button->setText(buttonName);


        switch (i)
        {
        case 1:
            ui->lundi->addWidget(button);
            break;
        case 2: ui->mardi->addWidget(button);
            break;
        case 3: ui->mercredi->addWidget(button);
            break;
        case 4: ui->jeudi->addWidget(button);
            break;
        case 5: ui->vendredi->addWidget(button);
            break;
        case 6: ui->samedi->addWidget(button);
            break;
        case 7: ui->dimanche->addWidget(button);
            break;

             }
        i++;
       }

   }

}



//////////SLOTS

void WeekCalendar::augmenterDate(){
    dateDebutSemaine = dateDebutSemaine.addDays(7);
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
    chargerSemaine(dateDebutSemaine);

}

void WeekCalendar::reduireDate(){
    dateDebutSemaine = dateDebutSemaine.addDays(-7);
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
    chargerSemaine(dateDebutSemaine);

}



void WeekCalendar::updateDateLundi()
{
    dateDebutSemaine = ui->dateLundi->date().addDays(1- ui->dateLundi->date().dayOfWeek());
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
    chargerSemaine(dateDebutSemaine);
}

void WeekCalendar::updateDateDimanche()
{
    dateDebutSemaine = ui->dateDimanche->date().addDays(1- ui->dateLundi->date().dayOfWeek());
    ui->dateLundi->setDate(dateDebutSemaine);
    ui->dateDimanche->setDate(dateDebutSemaine.addDays(6));
    chargerSemaine(dateDebutSemaine);

}

void WeekCalendar::ajouterActivite()
{
    EvenementSimpleEditor ese(0,0);
    ese.exec();
    chargerSemaine(dateDebutSemaine);
}

void WeekCalendar::programmerTache()
{
    TacheProgrammeur tp;
    tp.exec();
    chargerSemaine(dateDebutSemaine);
}

void WeekCalendar::lancerExport()
{
    //Ajouter l'export
}

void WeekCalendar::lancerListeEvenements(){
    EvenementEditor ee;
    ee.exec();
    chargerSemaine(dateDebutSemaine);
}

