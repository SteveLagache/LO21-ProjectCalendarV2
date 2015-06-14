#ifndef PROJETEDITOR_H
#define PROJETEDITOR_H

#include <QDialog>
#include "projetmanager.h"

/*!
 * \file projeteditor.h
 * \brief Fenetre d'édition des projets
 * \author Guyet-Lagache
 */

namespace Ui {
class ProjetEditor;
}
///
/// \brief The ProjetEditor class
///
class ProjetEditor : public QDialog
{
    Q_OBJECT

private:
    Ui::ProjetEditor *ui;
    Projet* projet;

public:
    ////
    /// \brief Fenetre de création et modification des projets
    /// \param parent : Widget parent
    /// \param p : adresse du projet à modifier (=0 si création)
    ///
    explicit ProjetEditor(QWidget *parent = 0, Projet *p = 0);
    ~ProjetEditor();

public slots:
    void sauvegarder();

};

#endif // PROJETEDITOR_H
