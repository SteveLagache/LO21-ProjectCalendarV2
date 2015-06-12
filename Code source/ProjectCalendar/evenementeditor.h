#ifndef EVENEMENTEDITOR_H
#define EVENEMENTEDITOR_H

#include <QDialog>

namespace Ui {
class EvenementEditor;
}

class EvenementEditor : public QDialog
{
    Q_OBJECT

public:
    explicit EvenementEditor(QWidget *parent = 0);
    ~EvenementEditor();

private:
    Ui::EvenementEditor *ui;
};

#endif // EVENEMENTEDITOR_H
