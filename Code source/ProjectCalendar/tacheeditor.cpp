#include "tacheeditor.h"
#include "ui_tacheeditor.h"
#include "tachemanager.h"
#include <QtDebug>


TacheEditor::TacheEditor(QWidget *parent, Tache* t, Projet *_projetParent, Tache* _tacheParent) :
    QDialog(parent),
    ui(new Ui::TacheEditor)
{
    tache = t;
    tacheParent = _tacheParent;
    projetParent=_projetParent;
    ui->setupUi(this);
    if (t == 0){
         ui->label_fenetre->setText("Création d'une nouvelle tâche");
    }
    else{
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
            TacheComposite* tc = dynamic_cast<TacheComposite*>(t);
            QString listeST= "Liste des sous-tâches de la tâche composite  \n \n CoucouS";
            listeST += t->getId();
            QList<Tache*>& ST=tc->getSousTaches();
            for (QList<Tache*>::iterator it = ST.begin(); it!=ST.end(); it++){
                listeST += "\n";
                listeST += (*it)->getId();
            }
            ui->label_st->setText(listeST);
        }
        else { //t->getType()=="TacheUnitaire"
            TacheUnitaire * tu = dynamic_cast<TacheUnitaire*>(t);
            ui->editDureeHeures->setValue(tu->getDuree().getHeure());
            ui->editDureeMinutes->setValue(tu->getDuree().getMinute());
            if (tu->isPreemptive()) ui->checkBoxPreemp->setChecked(true);
        }
    }

    ////SLOTS
    QObject::connect(ui->buttonSauvegarder, SIGNAL(clicked()), this, SLOT(sauvegarder()));
    QObject::connect(ui->buttonAnnuler, SIGNAL(clicked()), this, SLOT(close()));

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




///SLOTS

void TacheEditor::sauvegarder(){
    TacheManager& tm= TacheManager::getInstance();
    if (tache== 0){ // CREATION
        TacheUnitaire* tu= tm.ajouterTacheUnitaire(ui->edit_titre->text(), ui->editDispo->date(),ui->editEcheance->date(),Duree(ui->editDureeHeures->value(),ui->editDureeMinutes->value()),ui->checkBoxPreemp->isChecked());
        if(projetParent != 0){
            projetParent->ajouterTache(tu);
        }
        if (tacheParent != 0){
        try{
            TacheComposite* tc= tm.ajouterTacheComposite(tacheParent->getTitre(),tacheParent->getDateDisponibilite(),tacheParent->getDateEcheance());
            tacheParent=tm.remplacerTache(tacheParent, tc);
            qDebug() << tacheParent->getType();
            tc = dynamic_cast<TacheComposite*>(tacheParent);
            tc->ajouterSousTache(tu);
        }
        catch(CalendarException e){
            e.afficherWarning();
        }
        }
    }
    else{
        try{ // MODIFICATION
            tache->setTitre(ui->edit_titre->text());
        }
        catch(CalendarException e){
            e.afficherWarning();
        }
        tache->setDatesDisponibiliteEcheance(ui->editDispo->date(), ui->editEcheance->date());
        QMessageBox::information(0, "Modification réussie", "Votre tâche a été modifiée.");
        if(tache->getType()=="TacheUnitaire"){
            TacheUnitaire* tu= dynamic_cast<TacheUnitaire*>(tache);
            if (ui->checkBoxPreemp->isChecked()) tu->setPreemptive();
            else tu->setNonPreemptive();
            try{
                tu->setDuree(Duree(ui->editDureeHeures->value(), ui->editDureeMinutes->value()));
            }
            catch(CalendarException e){
                e.afficherWarning();
            }
        }

    }

};
