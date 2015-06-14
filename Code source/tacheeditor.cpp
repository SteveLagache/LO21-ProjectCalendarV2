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
        if (tacheParent !=0){
            ui->editDispo->setDate(tacheParent->getDateDisponibilite());
            ui->editEcheance->setDate(tacheParent->getDateEcheance());
        }
        if (projetParent !=0){
            ui->editDispo->setDate(projetParent->getDateDisponibilite());
            ui->editEcheance->setDate(projetParent->getDateEcheance());
        }
        ui->editDureeHeures->setValue(1);
        ui->editDureeMinutes->setValue(0);
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
            QString listeST= "Liste des sous-tâches de la tâche composite ";
            listeST += t->getId()+" :";
            const QList<Tache*>& ST=tc->getSousTaches();
            for (QList<Tache*>::const_iterator it = ST.begin(); it!=ST.end(); it++){
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


TacheEditor::~TacheEditor()
{
    delete ui;
}




/////////////////////SLOTS

void TacheEditor::sauvegarder(){
    TacheManager& tm= TacheManager::getInstance();
    if (tache== 0){ // CREATION
        TacheUnitaire* tu= tm.ajouterTacheUnitaire(ui->edit_titre->text(), ui->editDispo->date(),ui->editEcheance->date(),Duree(ui->editDureeHeures->value(),ui->editDureeMinutes->value()),ui->checkBoxPreemp->isChecked());
        if(projetParent != 0){
            projetParent->ajouterTache(tu);
            QMessageBox::information(0, "Ajout réussi", "Votre tâche a bien été créée.");
            close();
            TacheEditor te(0, tu);
            te.exec();
        }
        if (tacheParent != 0){
            TacheComposite* tc = dynamic_cast<TacheComposite*>(tacheParent);
            if(tacheParent->getType() =="TacheUnitaire"){
                tc= tm.ajouterTacheComposite(tacheParent->getTitre(),tacheParent->getDateDisponibilite(),tacheParent->getDateEcheance());
                Tache* old=tacheParent;
                TacheComposite* tacheMere =tacheParent->getTacheMere();
                if (tacheMere != 0){
                    tacheMere->supprimerSousTache(old);
                    tacheMere->ajouterSousTache(tc);
                    tm.supprimerTache(old);
                }
                else{
                    Projet* projetPere= tacheParent->getProjetPere();
                    projetPere->supprimerTache(old);
                    projetPere->ajouterTache(tc);
                    tm.supprimerTache(old);
                }
                tacheParent=tc;
            }
            tc->ajouterSousTache(tu);
            QMessageBox::information(0, "Ajout réussi", "Votre tâche a bien été créée.");
            close();
            TacheEditor te(0, tu);
            te.exec();
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
        QMessageBox::information(0, "Modification réussie", "Votre tâche a été modifiée.");
    }

};
