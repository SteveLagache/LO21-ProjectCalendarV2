#include "evenementsimpleeditor.h"
#include "ui_evenementsimpleeditor.h"

EvenementSimpleEditor::EvenementSimpleEditor(QWidget *parent, EvenementSimple* es) :
    QDialog(parent),
    ui(new Ui::EvenementSimpleEditor)
{
    ui->setupUi(this);
}

EvenementSimpleEditor::~EvenementSimpleEditor()
{
    delete ui;
}
