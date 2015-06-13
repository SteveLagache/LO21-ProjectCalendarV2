#include "evenementsimpleeditor.h"
#include "ui_evenementsimpleeditor.h"

EvenementSimpleEditor::EvenementSimpleEditor(QWidget *parent, EvenementSimple* es) :
    QDialog(parent),
    ui(new Ui::EvenementSimpleEditor)
{
ui->setupUi(this);

    evt = es;

    if(evt==0){//CREATION PROGRAMMATION
        ui->edit_debut->setDateTime(QDateTime::currentDateTime());
        ui->edit_fin->setDateTime(ui->edit_debut->dateTime().addSecs(3600));
    }
    else{
        ui->label_fenetre->setText("Modification de l'évenement : "+evt->getId());
        ui->edit_titre->setText(evt->getTitre());
        ui->edit_debut->setDateTime(evt->getDateDebut());
        ui->edit_fin->setDateTime(evt->getDateFin());
        ui->edit_lieu->setText(evt->getLieu());
}

    QObject::connect(ui->buttonSauvegarder, SIGNAL(clicked()), this, SLOT(sauvegarder()));
}

EvenementSimpleEditor::~EvenementSimpleEditor()
{
    delete ui;
}

void EvenementSimpleEditor::sauvegarder()
{
      Agenda& a = Agenda::getInstance();
      if(evt==0){//CREATION PROGRAMMATION
        try{
        EvenementSimple* es =a.ajouterEvenementSimple(ui->edit_titre->text(),ui->edit_participants->text(),ui->edit_debut->dateTime(), ui->edit_fin->dateTime(),ui->edit_lieu->text());

        QMessageBox::information(0,"Création réussie", "Votre activité a bien été programmée");
        EvenementSimpleEditor ese(0, es);
        close();
        ese.exec();
        }
        catch(CalendarException e){
            e.afficherWarning();
        }
    }
    else{//MODIFICATION

            EvenementSimple* ancien = new EvenementSimple(evt->getTitre(),evt->getPersonnes(),evt->getDateDebut(),evt->getDateFin(),evt->getLieu());
            EvenementSimple* evtModifie = new EvenementSimple(ui->edit_titre->text(),ui->edit_participants->text(),ui->edit_debut->dateTime(),ui->edit_fin->dateTime(),ui->edit_lieu->text());

            try{
            a.supprimerEvenement(evt);
            a.ajouterEvenement(evtModifie);

            if (a.trouverEvenement(evtModifie->getId())==0)
                throw CalendarException("La modification n'a pas été faite");

            QMessageBox::information(0, "Modification réussie", "La modification de la programmation de l'activité a bien été modifiée");
        }
        catch(CalendarException e)
        {
            e.afficherWarning();
            a.ajouterEvenement(ancien);
        }
    }
}

