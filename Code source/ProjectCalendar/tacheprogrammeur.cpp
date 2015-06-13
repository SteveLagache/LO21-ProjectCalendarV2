#include "tacheprogrammeur.h"
#include "ui_tacheprogrammeur.h"
#include "evenementtacheeditor.h"
#include "tachemanager.h"
#include <QStringRef>

TacheProgrammeur::TacheProgrammeur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TacheProgrammeur)
{
    ui->setupUi(this);
    chargerListe();

     QObject::connect(ui->listWidgetNonProgrammables, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(disableProgrammation()));
     QObject::connect(ui->listWidgetProgrammables, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(enableProgrammation()));
     QObject::connect(ui->buttonProgrammer, SIGNAL(clicked()), this, SLOT(programmerTache()));


}

TacheProgrammeur::~TacheProgrammeur()
{
    delete ui;
    chargerListe();
}

void TacheProgrammeur::chargerListe(){
    ui->listWidgetProgrammables->clear();
    ui->listWidgetNonProgrammables->clear();
    TacheManager& tm=TacheManager::getInstance();
    QVector<Tache*> taches =tm.getTaches();
    QList<Tache*> listeTachesProgrammables;
    QList<Tache*> listeTachesNonProgrammables;
    for (QVector<Tache*>::const_iterator it = taches.begin(); it!=taches.end(); it++){
        if ((*it)->getType()=="TacheUnitaire"){
            if ((*it)->isProgrammable())
                 listeTachesProgrammables.push_back((*it));
            if (!(*it)->isProgrammee()) listeTachesNonProgrammables.push_back((*it));
        }
    }
    for(QList<Tache*>::const_iterator it = listeTachesProgrammables.begin(); it!=listeTachesProgrammables.end(); it++){
        QListWidgetItem * item = new QListWidgetItem((*it)->getId() + " - " + (*it)->getTitre());
        ui->listWidgetProgrammables->addItem(item);
    }
    for(QList<Tache*>::const_iterator it = listeTachesNonProgrammables.begin(); it!=listeTachesNonProgrammables.end(); it++){
        QListWidgetItem * item = new QListWidgetItem((*it)->getId() + " - " + (*it)->getTitre());
        ui->listWidgetNonProgrammables->addItem(item);
    }
}





///
/// SLOTS
///


void TacheProgrammeur::programmerTache()
{
    QListWidgetItem* item =ui->listWidgetProgrammables->selectedItems()[0];
    TacheManager& tm = TacheManager::getInstance();
    QString str = item->text();
    QString id=str.left(5);
    TacheUnitaire* t=dynamic_cast<TacheUnitaire*>(tm.trouverTache(id));
    EvenementTacheEditor ete(0,0,t);
    ete.exec();
    chargerListe();
}

void TacheProgrammeur::enableProgrammation(){
    ui->buttonProgrammer->setEnabled(true);
}

void TacheProgrammeur::disableProgrammation(){
  //  QListWidgetItem* item =ui->listWidgetNonProgrammables->selectedItems()[0];

    ui->buttonProgrammer->setEnabled(false);
}
