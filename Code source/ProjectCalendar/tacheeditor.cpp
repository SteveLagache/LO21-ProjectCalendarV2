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
    if (t->getType()=="TacheComposite"){
        ui->editDuree->setEnabled(false);
        ui->checkBoxPreemp->setEnabled(false);
        ui->label_duree->setEnabled(false);
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
