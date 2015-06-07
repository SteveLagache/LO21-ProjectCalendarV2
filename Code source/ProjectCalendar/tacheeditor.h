#ifndef TACHEEDITOR_H
#define TACHEEDITOR_H

#include <QDialog>
#include "tache.h"


namespace Ui {
class TacheEditor;
}

class TacheEditor : public QDialog
{
    Q_OBJECT

public:
    TacheEditor(QWidget *parent = 0, Tache *t =0);
    ~TacheEditor();

private:
    Ui::TacheEditor *ui;
};

#endif // TACHEEDITOR_H
