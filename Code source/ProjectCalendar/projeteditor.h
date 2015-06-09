#ifndef PROJETEDITOR_H
#define PROJETEDITOR_H

#include <QDialog>
#include "projetmanager.h"

namespace Ui {
class ProjetEditor;
}

class ProjetEditor : public QDialog
{
    Q_OBJECT

public:
    explicit ProjetEditor(QWidget *parent = 0, Projet *p = 0);
    ~ProjetEditor();

private:
    Ui::ProjetEditor *ui;
};

#endif // PROJETEDITOR_H
