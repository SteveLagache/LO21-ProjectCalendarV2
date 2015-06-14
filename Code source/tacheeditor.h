#ifndef TACHEEDITOR_H
#define TACHEEDITOR_H

#include <QDialog>
#include "tache.h"
#include "projetmanager.h"

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

///
/// \brief The TacheEditor class
///
class TacheEditor : public QDialog
{
    Q_OBJECT

public:
    ///
    /// \brief Fenetre de création et modification de tâches
    /// \param parent : Widget parent
    /// \param t : Tache* adresse de la tache à modifier (=0 si création)
    /// \param _projetParent : adresse du projet dans lequel nous allons ajouter la nouvelle tâche
    /// \param _tacheParent : adresse de la Tache Composite dans laquelle nous allons ajouter la tâche
    ///
    TacheEditor(QWidget *parent = 0, Tache *t =0, Projet* _projetParent =0, Tache* _tacheParent =0);
    ~TacheEditor();

private:
    Ui::TacheEditor *ui;
    Tache* tache;
    Projet* projetParent;
    Tache* tacheParent;

public slots:
    void sauvegarder();


};

#endif // TACHEEDITOR_H
