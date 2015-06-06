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
        QTreeWidgetItem* projetItem = new QTreeWidgetItem(QStringList((*it)->getTitre()));
        arbre->addTopLevelItem(projetItem);
        chargerTaches(projetItem, (*it));
    }

};

void ProjectCalendar::chargerTaches(QTreeWidgetItem* projetItem, Projet* projet){
    for (QList<Tache*>::Iterator it = projet->getTaches().begin(); it != projet->getTaches().end(); ++it){
        QTreeWidgetItem* tacheItem = new QTreeWidgetItem(QStringList((*it)->getTitre()));
        QString str =(*it)->getTitre();
        projetItem->addChild(tacheItem);
        if ((*it)->getType()=="TacheComposite")
            chargerTaches(tacheItem, dynamic_cast<TacheComposite*>(*it));
    }
}


void ProjectCalendar::chargerTaches(QTreeWidgetItem* projetItem, TacheComposite *tache){
    for (QList<Tache*>::Iterator it = tache->getSousTaches().begin(); it != tache->getSousTaches().end(); ++it){
        QTreeWidgetItem* tacheItem = new QTreeWidgetItem(QStringList((*it)->getTitre()));
        projetItem->addChild(tacheItem);
        if ((*it)->getType()=="TacheComposite")
            chargerTaches(tacheItem, dynamic_cast<TacheComposite*>(*it));
    }
}
