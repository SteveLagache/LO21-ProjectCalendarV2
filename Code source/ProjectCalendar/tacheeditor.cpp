#include "tacheeditor.h"
#include "ui_tacheeditor.h"

TacheEditor::TacheEditor(QWidget *parent, Tache* t) :
    QDialog(parent),
    ui(new Ui::TacheEditor)
{
    ui->setupUi(this);
    QString newLabel = ui->label_fenetre->text();
    newLabel += t->getId();
    ui->label_fenetre->setText(newLabel);
    ui->edit_titre->setText(t->getTitre());
    ui->editDispo->setDate(t->getDateDisponibilite());
    ui->editEcheance->setDate(t->getDateEcheance());
    if (t->getType()=="TacheComposite"){
        ui->editDureeHeures->setEnabled(false);
        ui->editDureeMinutes->setEnabled(false);
        ui->checkBoxPreemp->setEnabled(false);
        ui->label_duree->setEnabled(false);
        ui->label_minutes->setEnabled(false);
        ui->label_heures->setEnabled(false);
    }
    else { //t->getType()=="TacheUnitaire"
        TacheUnitaire * tu = dynamic_cast<TacheUnitaire*>(t);
        ui->editDureeHeures->setValue(tu->getDuree().getHeure());
        ui->editDureeMinutes->setValue(tu->getDuree().getMinute());
        if (tu->isPreemptive()) ui->checkBoxPreemp->setChecked(true);
    }

}

//TacheEditor::TacheEditor(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::TacheEditor)
//{
//    ui->setupUi(this);
//    QString newLabel = "Création d'une nouvelle tâche"
//    ui->label_fenetre->setText(newLabel);
//}

TacheEditor::~TacheEditor()
{
    delete ui;
}
