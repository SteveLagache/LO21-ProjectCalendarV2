#include "evenementtacheeditor.h"
#include "ui_evenementtacheeditor.h"

EvenementTacheEditor::EvenementTacheEditor(QWidget *parent,  EvenementTache* et, TacheUnitaire *t) :
    QDialog(parent),
    ui(new Ui::EvenementTacheEditor)
{
    tu= t;
    evt=et;

    ui->setupUi(this);

    if(tu!=0){//CREATION PROGRAMMATION
        ui->edit_titre->setText(tu->getTitre());
        ui->edit_debut->setDateTime(QDateTime::currentDateTime());
        ui->edit_fin->setDateTime(ui->edit_debut->dateTime().addSecs(tu->getDuree().getDureeEnMinutes()*60));
        ui->label_idTache->setText(tu->getId());
    }
    else{
        ui->labe_fenetre->setText("Modification de l'évenement : "+evt->getId());
        ui->edit_titre->setText(evt->getTitre());
        ui->edit_debut->setDateTime(evt->getDateDebut());
        ui->edit_fin->setDateTime(evt->getDateFin());
        ui->label_idTache->setText(evt->getTache()->getId());
}

    QObject::connect(ui->buttonSauvegarder, SIGNAL(clicked()), this, SLOT(sauvegarder()));
}

EvenementTacheEditor::~EvenementTacheEditor()
{
    delete ui;
}

void EvenementTacheEditor::sauvegarder()
{
    if(evt==0){//CREATION PROGRAMMATION
        Agenda& a = Agenda::getInstance();
        try{
        EvenementTache* et =a.ajouterEvenementTache(ui->edit_titre->text(),ui->edit_participants->text(),ui->edit_debut->dateTime(), ui->edit_fin->dateTime(),tu);
        QMessageBox::information(0,"Création réussie", "Votre tâche a bien été programmée");
        EvenementTacheEditor ete(0, et);
        close();
        ete.exec();
        }
        catch(CalendarException e){
            e.afficherWarning();
        }
    }
    else{//MODIFICATION
        try{
            evt->setDatesDebutFin(ui->edit_debut->dateTime(),ui->edit_fin->dateTime());
            evt->setTitre(ui->edit_titre->text());
            evt->setPersonnes(ui->edit_participants->text());
            QMessageBox::information(0, "Modification réussie", "La modification de la programmation de la tâche a bien été modifiée");
        }
        catch(CalendarException e)
        {
            e.afficherWarning();
        }
    }
}
