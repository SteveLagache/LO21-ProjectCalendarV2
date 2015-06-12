#include "evenementtacheeditor.h"
#include "ui_evenementtacheeditor.h"

EvenementTacheEditor::EvenementTacheEditor(QWidget *parent,  EvenementTache* et) :
    QDialog(parent),
    ui(new Ui::EvenementTacheEditor)
{
    ui->setupUi(this);
}

EvenementTacheEditor::~EvenementTacheEditor()
{
    delete ui;
}
