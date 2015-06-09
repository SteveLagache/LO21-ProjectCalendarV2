#include "projectcalendar.h"
#include "weekcalendar.h"
#include "ui_projectcalendar.h"


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


//    QTreeWidgetItem* projet = new QTreeWidgetItem("Projet");
//    projet->addChild();

}

ProjectCalendar::~ProjectCalendar()
{
    delete ui;
}

void ProjectCalendar::chargerArbre(QTreeWidget* arbre){
    ProjetManager& pm= ProjetManager::getInstance();
    for (QVector<Projet*>::Iterator it = pm.getProjets().begin(); it != pm.getProjets().end(); ++it){
        QStringList liste((*it)->getTitre());
        liste.push_back((*it)->getTitre());
        QTreeWidgetItem* projetItem = new QTreeWidgetItem(liste);
        arbre->addTopLevelItem(projetItem);
        chargerTaches(projetItem, (*it));
    }

};

void ProjectCalendar::chargerTaches(QTreeWidgetItem* projetItem, Projet* projet){
    for (QList<Tache*>::Iterator it = projet->getTaches().begin(); it != projet->getTaches().end(); ++it){
        QStringList liste((*it)->getTitre());
        liste.push_back((*it)->getId());
        QTreeWidgetItem* tacheItem = new QTreeWidgetItem(liste);
        QString str =(*it)->getTitre();
        projetItem->addChild(tacheItem);
        if ((*it)->getType()=="TacheComposite")
            chargerTaches(tacheItem, dynamic_cast<TacheComposite*>(*it));
    }
}


void ProjectCalendar::chargerTaches(QTreeWidgetItem* projetItem, TacheComposite *tache){
    for (QList<Tache*>::Iterator it = tache->getSousTaches().begin(); it != tache->getSousTaches().end(); ++it){
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
     }
     else {
        TacheEditor te(0, t);
        te.exec();
     }
 }

void ProjectCalendar::ajouterProjet(){
/// A FAIRE
}
