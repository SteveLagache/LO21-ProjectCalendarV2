#include "projeteditor.h"
#include "ui_projeteditor.h"

ProjetEditor::ProjetEditor(QWidget *parent, Projet* p) :
    QDialog(parent),
    ui(new Ui::ProjetEditor)
{
    ui->setupUi(this);
    projet =p;
    if (p == 0){
        ui->label_fenetre->setText("Création d'un nouveau projet");
        QDate aujourdhui =QDate::currentDate();
        ui->editDispo->setDate(aujourdhui);
        ui->editEcheance->setDate(aujourdhui.addDays(7));
    }
    else {
        QString newLabel = ui->label_fenetre->text();
        newLabel += p->getTitre();
        ui->label_fenetre->setText(newLabel);
        ui->edit_titre->setText(p->getTitre());
        ui->editDispo->setDate(p->getDateDisponibilite());
        ui->editEcheance->setDate(p->getDateEcheance());
    }

    QObject::connect(ui->buttonSauvegarder, SIGNAL(clicked()), this, SLOT(sauvegarder()));
    QObject::connect(ui->buttonAnnuler, SIGNAL(clicked()), this, SLOT(close()));

}

ProjetEditor::~ProjetEditor()
{
    delete ui;
}


///SLOTS

void ProjetEditor::sauvegarder(){
    ProjetManager& pm= ProjetManager::getInstance();
    if (projet == 0){ // CREATION
        try{
            Projet* p = pm.ajouterProjet(ui->edit_titre->text(), ui->editDispo->date(),ui->editEcheance->date());
            QMessageBox::information(0, "Ajout réussi", "Votre nouveau projet a été créé.");
            close();
            ProjetEditor pe(0, p);
            pe.exec();
        }
        catch(CalendarException e){
            e.afficherWarning();
        }
    }
    else{
        try{ // MODIFICATION
            projet->setTitre(ui->edit_titre->text());
        }
        catch(CalendarException e){
            e.afficherWarning();
        }

        projet->setDatesDisponibiliteEcheance(ui->editDispo->date(), ui->editEcheance->date());
        QMessageBox::information(0, "Modification réussie", "Votre projet a été modifié.");
    }

};
