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

private:
    Ui::ProjetEditor *ui;
    Projet* projet;

public:
    explicit ProjetEditor(QWidget *parent = 0, Projet *p = 0);
    ~ProjetEditor();

public slots:
    void sauvegarder();

};

#endif // PROJETEDITOR_H
