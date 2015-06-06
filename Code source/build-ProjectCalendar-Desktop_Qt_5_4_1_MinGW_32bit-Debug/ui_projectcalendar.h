/********************************************************************************
** Form generated from reading UI file 'projectcalendar.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTCALENDAR_H
#define UI_PROJECTCALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectCalendar
{
public:
    QAction *actionQuitter;
    QAction *actionQuitter_2;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuA_propos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProjectCalendar)
    {
        if (ProjectCalendar->objectName().isEmpty())
            ProjectCalendar->setObjectName(QStringLiteral("ProjectCalendar"));
        ProjectCalendar->resize(1203, 930);
        actionQuitter = new QAction(ProjectCalendar);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionQuitter_2 = new QAction(ProjectCalendar);
        actionQuitter_2->setObjectName(QStringLiteral("actionQuitter_2"));
        centralwidget = new QWidget(ProjectCalendar);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMaximumSize(QSize(500, 16777215));

        verticalLayout->addWidget(treeWidget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout);

        ProjectCalendar->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProjectCalendar);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1203, 31));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuA_propos = new QMenu(menubar);
        menuA_propos->setObjectName(QStringLiteral("menuA_propos"));
        ProjectCalendar->setMenuBar(menubar);
        statusbar = new QStatusBar(ProjectCalendar);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ProjectCalendar->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuA_propos->menuAction());
        menuFichier->addAction(actionQuitter);
        menuFichier->addAction(actionQuitter_2);

        retranslateUi(ProjectCalendar);

        QMetaObject::connectSlotsByName(ProjectCalendar);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectCalendar)
    {
        ProjectCalendar->setWindowTitle(QApplication::translate("ProjectCalendar", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("ProjectCalendar", "Charger sauvegarde", 0));
        actionQuitter_2->setText(QApplication::translate("ProjectCalendar", "Quitter", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ProjectCalendar", "Titres des t\303\242ches", 0));
        pushButton->setText(QApplication::translate("ProjectCalendar", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("ProjectCalendar", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("ProjectCalendar", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("ProjectCalendar", "PushButton", 0));
        menuFichier->setTitle(QApplication::translate("ProjectCalendar", "Fichier", 0));
        menuA_propos->setTitle(QApplication::translate("ProjectCalendar", "A propos", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjectCalendar: public Ui_ProjectCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTCALENDAR_H
