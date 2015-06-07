#ifndef TACHEEDITOR_H
#define TACHEEDITOR_H

#include <QDialog>
#include "tache.h"


/*!
 * \file tacheeditor.h
 * \brief Fenêtre d'édition de tâches
 * \author Guyet-Lagache
 */

/**
 * \class TacheEditor
 * \brief Fenêtre d'édition de tâches
 */
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
