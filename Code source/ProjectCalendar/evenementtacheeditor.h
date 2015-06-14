#ifndef EVENEMENTTACHEEDITOR_H
#define EVENEMENTTACHEEDITOR_H

#include <QDialog>
#include "agenda.h"

/*!
 * \file eenementsimpleeditor.h
 * \brief Fenetre d'édition et création des tâches simples (activités)
 * \author Guyet-Lagache
 */

namespace Ui {
class EvenementTacheEditor;
}

///
/// \brief The EvenementTacheEditor class
///
class EvenementTacheEditor : public QDialog
{
    Q_OBJECT

public:
    ///
    /// \brief Constructeur de EvenementTacheEditor
    /// \param parent : Widget parent
    /// \param et : EvenementTache* : adresse de l'EvenementTache à modifier (=0 si création)
    /// \param t : TacheUnitaire* : adresse de la tâcheà lier à l'évènement (=0 si modification)
    ///
    explicit EvenementTacheEditor(QWidget *parent = 0, EvenementTache* et =0, TacheUnitaire* t =0);
    ~EvenementTacheEditor();

private:
    Ui::EvenementTacheEditor *ui;
    EvenementTache* evt;
    TacheUnitaire* tu;

public slots:
    ////
    /// \brief sauvegarder
    ///
    /// Création ou modification de l'EvènementTache
    ///
    void sauvegarder();

};

#endif // EVENEMENTTACHEEDITOR_H
