#include "projeteditor.h"
#include "ui_projeteditor.h"

ProjetEditor::ProjetEditor(QWidget *parent, Projet* p) :
    QDialog(parent),
    ui(new Ui::ProjetEditor)
{
    ui->setupUi(this);


    QString newLabel = ui->label_fenetre->text();
    newLabel += p->getTitre();
    ui->label_fenetre->setText(newLabel);
    ui->edit_titre->setText(p->getTitre());
    ui->editDispo->setDate(p->getDateDisponibilite());
    ui->editEcheance->setDate(p->getDateEcheance());

}

ProjetEditor::~ProjetEditor()
{
    delete ui;
}
