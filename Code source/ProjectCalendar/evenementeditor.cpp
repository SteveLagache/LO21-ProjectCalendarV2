#include "evenementeditor.h"
#include "ui_evenementeditor.h"

EvenementEditor::EvenementEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EvenementEditor)
{
    ui->setupUi(this);
}

EvenementEditor::~EvenementEditor()
{
    delete ui;
}
