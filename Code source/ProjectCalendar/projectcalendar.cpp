#include "projectcalendar.h"
#include "weekcalendar.h"
#include "ui_projectcalendar.h"
#include "evenementtacheeditor.h"


ProjectCalendar::ProjectCalendar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProjectCalendar)
{
    ui->setupUi(this);
    calendrierSemaine= new WeekCalendar(centralWidget());
    centralWidget()->layout()->addWidget(calendrierSemaine);

    QTreeWidget* arbre= ui->treeWidget;
    chargerArbre(arbre);


///Connections manuelles
    QObject::connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(enableAjouterTache()));
    QObject::connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(enableSupprimer()));
    QObject::connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(modifierElement()));
    QObject::connect(ui->buttonAjoutProjet, SIGNAL(clicked()), this, SLOT(ajouterProjet()));
    QObject::connect(ui->buttonAjoutTache, SIGNAL(clicked()), this, SLOT(ajouterTache()));
    QObject::connect(ui->buttonSupprimer, SIGNAL(clicked()), this, SLOT(supprimerElement()));
    QObject::connect(ui->buttonProgrammer, SIGNAL(clicked()), this, SLOT(programmerTache()));
    QObject::connect(ui->monter, SIGNAL(clicked()), this, SLOT(monterTache()));
    QObject::connect(ui->descendre, SIGNAL(clicked()), this, SLOT(descendreTache()));
    QObject::connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(enableFleches()));
    QObject::connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(enableProgrammer()));


//    QTreeWidgetItem* projet = new QTreeWidgetItem("Projet");
//    projet->addChild();

}

ProjectCalendar::~ProjectCalendar()
{
    delete ui;
}

void ProjectCalendar::chargerArbre(QTreeWidget* arbre){
    arbre->clear();
    ui->buttonAjoutTache->setEnabled(false);
    ui->buttonSupprimer->setEnabled(false);
    ui->monter->setEnabled(false);
    ui->descendre->setEnabled(false);
    ui->buttonProgrammer->setEnabled(false);
    ProjetManager& pm= ProjetManager::getInstance();
    for (QVector<Projet*>::const_iterator it = pm.getProjets().begin(); it != pm.getProjets().end(); ++it){
        QStringList liste((*it)->getTitre());
        liste.push_back((*it)->getTitre());
        QTreeWidgetItem* projetItem = new QTreeWidgetItem(liste);
        arbre->addTopLevelItem(projetItem);
        chargerTaches(projetItem, (*it));
    }
    arbre->expandAll();
};

void ProjectCalendar::chargerTaches(QTreeWidgetItem* projetItem, Projet* projet){
    for (QList<Tache*>::const_iterator it = projet->getTaches().begin(); it != projet->getTaches().end(); ++it){
        QStringList liste((*it)->getTitre());
        liste.push_back((*it)->getId());
        QTreeWidgetItem* tacheItem = new QTreeWidgetItem(liste);
        QString str =(*it)->getTitre();
        projetItem->addChild(tacheItem);
        qDebug() << (*it)->getType();
        if ((*it)->getType()=="TacheComposite")
            chargerTaches(tacheItem, dynamic_cast<TacheComposite*>(*it));
    }
}


void ProjectCalendar::chargerTaches(QTreeWidgetItem* projetItem, TacheComposite *tache){
    for (QList<Tache*>::const_iterator it = tache->getSousTaches().begin(); it != tache->getSousTaches().end(); ++it){
        QStringList liste((*it)->getTitre());
        liste.push_back((*it)->getId());
        QTreeWidgetItem* tacheItem = new QTreeWidgetItem(liste);

        projetItem->addChild(tacheItem);
        if ((*it)->getType()=="TacheComposite")
            chargerTaches(tacheItem, dynamic_cast<TacheComposite*>(*it));
    }
}

///SLOTS
void ProjectCalendar::enableAjouterTache()
{
    ui->buttonAjoutTache->setEnabled(true);
}

void ProjectCalendar::enableSupprimer()
{
    ui->buttonSupprimer->setEnabled(true);
}


void ProjectCalendar::modifierElement(){
     QString id = ui->treeWidget->selectedItems()[0]->text(1);
     TacheManager& tm = TacheManager::getInstance();
     Tache* t = tm.trouverTache(id);
     if (t == 0) {//Ce n'est pas une tâche ==> projet
         ProjetManager& pm = ProjetManager::getInstance();
         Projet* p = pm.trouverProjet(id);
         ProjetEditor pe(0, p);
         pe.exec();
         chargerArbre(ui->treeWidget);
     }
     else {
        TacheEditor te(0, t);
        te.exec();
        chargerArbre(ui->treeWidget);
     }
 }


void ProjectCalendar::supprimerElement(){
    QString id = ui->treeWidget->selectedItems()[0]->text(1);
    TacheManager& tm = TacheManager::getInstance();
    Tache* t = tm.trouverTache(id);
    ProjetManager& pm = ProjetManager::getInstance();
    if (t == 0) {//Ce n'est pas une tâche ==> projet
        pm.supprimerProjet(id);
        QMessageBox::information(0, "Suppression réussie", "Votre projet a bien été supprimé.");
        chargerArbre(ui->treeWidget);
    }
    else {
       pm.supprimerTache(t);
       tm.supprimerTache(t);
       QMessageBox::information(0, "Suppression réussie", "Votre tâche a bien été supprimée.");
       chargerArbre(ui->treeWidget);
    }

};

void ProjectCalendar::monterTache(){
    QString id = ui->treeWidget->selectedItems()[0]->text(1);
    TacheManager& tm = TacheManager::getInstance();
    Tache* t = tm.trouverTache(id);
    TacheComposite* tacheMere = t->getTacheMere();
    if (tacheMere == 0){
       Projet* projetPere = t->getProjetPere();
       try{
            projetPere->monterPrecedence(t);
            chargerArbre(ui->treeWidget);
       }
       catch(CalendarException e){
           e.afficherWarning();
       }
    }
    else {
        try{
             tacheMere->monterSousTache(t);
             chargerArbre(ui->treeWidget);
        }
        catch(CalendarException e){
            e.afficherWarning();
        }
    }
};

void ProjectCalendar::descendreTache(){
    QString id = ui->treeWidget->selectedItems()[0]->text(1);
    TacheManager& tm = TacheManager::getInstance();
    Tache* t = tm.trouverTache(id);
    TacheComposite* tacheMere = t->getTacheMere();
    if (tacheMere == 0){
       Projet* projetPere = t->getProjetPere();
       try{
            projetPere->descendrePrecedence(t);
            chargerArbre(ui->treeWidget);
       }
       catch(CalendarException e){
           e.afficherWarning();
       }
    }
    else {
        try{
             tacheMere->descendreSousTache(t);
             chargerArbre(ui->treeWidget);
        }
        catch(CalendarException e){
            e.afficherWarning();
        }
    }
};

void ProjectCalendar::ajouterProjet(){
    ProjetEditor pe(0,0);
    pe.exec();
    chargerArbre(ui->treeWidget);
}

void ProjectCalendar::ajouterTache(){
    QString id = ui->treeWidget->selectedItems()[0]->text(1);
    TacheManager& tm = TacheManager::getInstance();
    Tache* t = tm.trouverTache(id);
    if (t == 0) {//Ce n'est pas une tâche ==> projet
        ProjetManager& pm = ProjetManager::getInstance();
        Projet* p = pm.trouverProjet(id);
        TacheEditor pe(0, 0, p, 0);
        pe.exec();
        chargerArbre(ui->treeWidget);
    }
    else {
       TacheEditor te(0, 0,0, t);
       te.exec();
       chargerArbre(ui->treeWidget);
    }

};

void ProjectCalendar::enableFleches(){
    QString id = ui->treeWidget->selectedItems()[0]->text(1);
    TacheManager& tm = TacheManager::getInstance();
    Tache* t = tm.trouverTache(id);
    if (t == 0) {//Ce n'est pas une tâche ==> projet
       ui->monter->setEnabled(false);
       ui->descendre->setEnabled(false);
    }
    else{
        TacheComposite* tacheMere = t->getTacheMere();
        if (tacheMere == 0){
           Projet* projetPere = t->getProjetPere();
           if (t == projetPere->getTaches()[0])
               ui->monter->setEnabled(false);
           else ui->monter->setEnabled(true);
           if (t == projetPere->getTaches()[projetPere->getTaches().size()-1])
               ui->descendre->setEnabled(false);
           else ui->descendre->setEnabled(true);
        }
        else{
            if (t == tacheMere->getSousTaches()[0])
                ui->monter->setEnabled(false);
            else ui->monter->setEnabled(true);
            if (t == tacheMere->getSousTaches()[tacheMere->getSousTaches().size()-1])
                ui->descendre->setEnabled(false);
            else ui->descendre->setEnabled(true);
        }
    }
}

void ProjectCalendar::enableProgrammer(){
    QString id = ui->treeWidget->selectedItems()[0]->text(1);
    TacheManager& tm = TacheManager::getInstance();
    Tache* t = tm.trouverTache(id);
    if (t == 0) {//Ce n'est pas une tâche ==> projet
       ui->buttonProgrammer->setEnabled(false);
    }
    else{
        if (t->getType()=="TacheUnitaire") ui->buttonProgrammer->setEnabled(true);
        else ui->buttonProgrammer->setEnabled(false);
    }
}

void ProjectCalendar::programmerTache()
{
    QString id = ui->treeWidget->selectedItems()[0]->text(1);
    TacheManager& tm = TacheManager::getInstance();
    TacheUnitaire* t = dynamic_cast<TacheUnitaire*>(tm.trouverTache(id));
    EvenementTacheEditor ete(0, 0, t);
    ete.exec();
}
