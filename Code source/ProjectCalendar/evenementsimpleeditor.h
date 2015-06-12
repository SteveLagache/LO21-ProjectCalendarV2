#ifndef EVENEMENTSIMPLEEDITOR_H
#define EVENEMENTSIMPLEEDITOR_H

#include <QDialog>
#include "agenda.h"

namespace Ui {
class EvenementSimpleEditor;
}

class EvenementSimpleEditor : public QDialog
{
    Q_OBJECT

public:
    explicit EvenementSimpleEditor(QWidget *parent = 0, EvenementSimple * es= 0);
    ~EvenementSimpleEditor();

private:
    Ui::EvenementSimpleEditor *ui;
};

#endif // EVENEMENTSIMPLEEDITOR_H
