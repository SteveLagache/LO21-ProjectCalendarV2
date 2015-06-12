#ifndef TACHEPROGRAMMEUR_H
#define TACHEPROGRAMMEUR_H

#include <QDialog>

namespace Ui {
class TacheProgrammeur;
}

class TacheProgrammeur : public QDialog
{
    Q_OBJECT

public:
    explicit TacheProgrammeur(QWidget *parent = 0);
    ~TacheProgrammeur();

private:
    Ui::TacheProgrammeur *ui;

public slots:
    void programmerTache();
};

#endif // TACHEPROGRAMMEUR_H
