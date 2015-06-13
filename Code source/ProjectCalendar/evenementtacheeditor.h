#ifndef EVENEMENTTACHEEDITOR_H
#define EVENEMENTTACHEEDITOR_H

#include <QDialog>
#include "agenda.h"

namespace Ui {
class EvenementTacheEditor;
}

class EvenementTacheEditor : public QDialog
{
    Q_OBJECT

public:
    explicit EvenementTacheEditor(QWidget *parent = 0, EvenementTache* et =0, TacheUnitaire* t =0);
    ~EvenementTacheEditor();

private:
    Ui::EvenementTacheEditor *ui;
    EvenementTache* evt;
    TacheUnitaire* tu;

public slots:
    void sauvegarder();

};

#endif // EVENEMENTTACHEEDITOR_H
