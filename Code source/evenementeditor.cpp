#include "evenementeditor.h"
#include "ui_evenementeditor.h"
#include "agenda.h"
#include "evenementsimpleeditor.h"
#include "evenementtacheeditor.h"

EvenementEditor::EvenementEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EvenementEditor)
{
    ui->setupUi(this);

    chargerArbre();

    QObject::connect(ui->treeWidgetEvenements, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(enableModification()));
    QObject::connect(ui->treeWidgetEvenements, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(enableSuppression()));
    QObject::connect(ui->buttonModifier, SIGNAL(clicked()), this, SLOT(modifierEvenement()));
    QObject::connect(ui->buttonSupprimer, SIGNAL(clicked()), this, SLOT(supprimerEvenement()));
}

EvenementEditor::~EvenementEditor()
{
    delete ui;
}




void EvenementEditor::chargerArbre(){
    ui->buttonModifier->setEnabled(false);
    ui->buttonSupprimer->setEnabled(false);
    ui->treeWidgetEvenements->clear();
    Agenda& a = Agenda::getInstance();
    for (QList<Evenement*>::const_iterator it = a.getEvenements().begin(); it!= a.getEvenements().end(); it++){
        QStringList listeAttributs;
        listeAttributs.push_back((*it)->getTitre());
        listeAttributs.push_back((*it)->getDateDebut().toString());
        listeAttributs.push_back((*it)->getDateFin().toString());
        listeAttributs.push_back((*it)->getId());
        QTreeWidgetItem * item = new QTreeWidgetItem(listeAttributs);
        ui->treeWidgetEvenements->addTopLevelItem(item);
    }
};



///SLOTS

void EvenementEditor::enableModification(){
    ui->buttonModifier->setEnabled(true);
};


void EvenementEditor::enableSuppression(){
    ui->buttonSupprimer->setEnabled(true);
}

void EvenementEditor::modifierEvenement(){
    QTreeWidgetItem* item =ui->treeWidgetEvenements->selectedItems()[0];
    QString id =item->text(3);
    Agenda& a = Agenda::getInstance();
    Evenement* e= a.trouverEvenement(id);

    if (e->getType()=="EvenementSimple"){
        EvenementSimple* es= dynamic_cast<EvenementSimple*>(e);
        EvenementSimpleEditor ese(0, es);
        ese.exec();
    }
    else {//EvenementTache
        EvenementTache* et= dynamic_cast<EvenementTache*>(e);
        EvenementTacheEditor ete(0, et);
        ete.exec();

    }
    chargerArbre();
}

void EvenementEditor::supprimerEvenement(){
    QTreeWidgetItem* item =ui->treeWidgetEvenements->selectedItems()[0];
    QString id =item->text(3);
    Agenda& a = Agenda::getInstance();
    Evenement* e= a.trouverEvenement(id);
    a.supprimerEvenement(e);
    QMessageBox::information(0, "Suppression réussie", "La programmation de l'activité a bien été supprimée");
    chargerArbre();

}
