#include "tacheprogrammeur.h"
#include "ui_tacheprogrammeur.h"
#include "evenementtacheeditor.h"

TacheProgrammeur::TacheProgrammeur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TacheProgrammeur)
{
    ui->setupUi(this);
}

TacheProgrammeur::~TacheProgrammeur()
{
    delete ui;
}

void TacheProgrammeur::programmerTache()
{
        EvenementTacheEditor ete(0,0);
        ete.exec();
}
