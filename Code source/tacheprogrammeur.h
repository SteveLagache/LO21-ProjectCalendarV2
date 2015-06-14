#ifndef TACHEPROGRAMMEUR_H
#define TACHEPROGRAMMEUR_H

#include <QDialog>

/*!
 * \file tacheprogrammeur.h
 * \brief Fenetre de programmation des tâches
 * \author Guyet-Lagache
 *
 */


namespace Ui {
class TacheProgrammeur;
}

////
/// \brief The TacheProgrammeur class
///
/// Contient une liste des tâches qu'il reste à programmer, et une liste des tâches programmables
///
class TacheProgrammeur : public QDialog
{
    Q_OBJECT

public:
    explicit TacheProgrammeur(QWidget *parent = 0);
    ~TacheProgrammeur();

    ///
    /// \brief Charge les deux listes
    ///
    /// Une liste des tâches qu'il reste à programmer, et une liste des tâches programmables
    ///
    void chargerListe();
private:
    Ui::TacheProgrammeur *ui;

public slots:

    ///
    /// \brief Programme la tâche programmable sélectionnée
    ///
    void programmerTache();

    ///
    /// \brief désactive le bouton de programmation
    ///
    /// Désactive le bouton si l'on clique sur une tâche qui se situe dans la liste des tâches qu'il reste à programmer (qui n'est pas forcément programmable)
    ///
    void disableProgrammation();

    ///
    /// \brief active le bouton de programmation si l'on clique sur une tpache programmable
    ///
    void enableProgrammation();
};

#endif // TACHEPROGRAMMEUR_H
