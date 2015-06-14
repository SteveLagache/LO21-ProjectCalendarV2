#ifndef EVENEMENTEDITOR_H
#define EVENEMENTEDITOR_H

#include <QDialog>

namespace Ui {
class EvenementEditor;
}

///
/// \brief The EvenementEditor class
///
/// Fenêtre permettant de voir la liste des événements programmés, les modifier et les supprimer.
///
class EvenementEditor : public QDialog
{
    Q_OBJECT

public:
    explicit EvenementEditor(QWidget *parent = 0);
    ~EvenementEditor();

    ///
    /// \brief Chargement des projets dans l'arbre
    ///
    void chargerArbre();

public slots:
    ///
    /// \brief Active le bouton modification
    ///
    /// Active le bouton modification lors d'un clic sur un Evenement dans la liste
    ///
    void enableModification();

    ///
    /// \brief Active le bouton suppression
    ///
    /// Active le bouton suppression lors d'un clic sur un Evenement dans la liste
    ///
    void enableSuppression();

    void modifierEvenement();
    void supprimerEvenement();

private:
    Ui::EvenementEditor *ui;
};

#endif // EVENEMENTEDITOR_H
