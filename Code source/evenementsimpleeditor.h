#ifndef EVENEMENTSIMPLEEDITOR_H
#define EVENEMENTSIMPLEEDITOR_H

/*!
 * \file eenementsimpleeditor.h
 * \brief Fenetre d'édition et création des tâches simples (activités)
 * \author Guyet-Lagache
 */

#include <QDialog>
#include "agenda.h"

namespace Ui {
class EvenementSimpleEditor;
}

///
/// \brief The EvenementSimpleEditor class
///
class EvenementSimpleEditor : public QDialog
{
    Q_OBJECT

public:
    ///
    /// \brief EvenementSimpleEditor
    /// \param parent : widget parent
    /// \param es : EvenementSimple* =0 si création, égal à l'adresse de l'événement à modifier;
    ///
    explicit EvenementSimpleEditor(QWidget *parent = 0, EvenementSimple * es= 0);
    ~EvenementSimpleEditor();

private:
    Ui::EvenementSimpleEditor *ui;
    EvenementSimple* evt;

public slots:
    ///
    /// \brief Sauvegarde de l'évènement simple
    ///
    /// Met à jour ou crée l'événement simple
    ///
    void sauvegarder();
};

#endif // EVENEMENTSIMPLEEDITOR_H
