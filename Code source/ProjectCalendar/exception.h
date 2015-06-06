#ifndef EXCEPTION_H
#define EXCEPTION_H

/*!
 * \file exception.h
 * \brief Exceptions du ProjectCalendar
 * \author Guyet-Lagache
 */

#include <QString>
#include <QMessageBox>

/**
 * \class CalendarException
 * \brief Exception du ProjectCalendar
 *
 * Les erreurs sont utilisés pour afficher des messages d'erreurs.
 */
class CalendarException{

private:
    QString info;

public:
    /**
     * \brief Constructeur de CalendarException
     * \param const QString& message : message d'erreur
     */
    CalendarException(const QString& message):info(message){}

    QString getInfo() const { return info; }

    /**
     * \brief Affiche un avertissement
     *
     * Ouvre une fenêtre d'avertissement contenant le message de l'exception
     */
    void afficherWarning(){
        QMessageBox::warning(0,"ATTENTION",this->getInfo());
    }

    /**
     * \brief Affiche une information
     *
     * Ouvre une fenêtre d'information contenant le message de l'exception
     */
    void afficherInfo(){
        QMessageBox::information(0,"Pour information",this->getInfo());
    }
};

#endif // EXCEPTION_H
