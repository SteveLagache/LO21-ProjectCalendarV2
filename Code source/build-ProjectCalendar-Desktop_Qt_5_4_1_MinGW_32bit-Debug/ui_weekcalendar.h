/********************************************************************************
** Form generated from reading UI file 'weekcalendar.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEEKCALENDAR_H
#define UI_WEEKCALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeekCalendar
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *lundi;
    QFrame *line;
    QWidget *mardi;
    QFrame *line_6;
    QWidget *mercredi;
    QFrame *line_2;
    QWidget *jeudi;
    QFrame *line_3;
    QWidget *vendredi;
    QFrame *line_4;
    QWidget *samedi;
    QFrame *line_5;
    QWidget *dimanche;

    void setupUi(QWidget *WeekCalendar)
    {
        if (WeekCalendar->objectName().isEmpty())
            WeekCalendar->setObjectName(QStringLiteral("WeekCalendar"));
        WeekCalendar->resize(999, 919);
        WeekCalendar->setMinimumSize(QSize(500, 0));
        horizontalLayout = new QHBoxLayout(WeekCalendar);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lundi = new QWidget(WeekCalendar);
        lundi->setObjectName(QStringLiteral("lundi"));

        horizontalLayout->addWidget(lundi);

        line = new QFrame(WeekCalendar);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        mardi = new QWidget(WeekCalendar);
        mardi->setObjectName(QStringLiteral("mardi"));

        horizontalLayout->addWidget(mardi);

        line_6 = new QFrame(WeekCalendar);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_6);

        mercredi = new QWidget(WeekCalendar);
        mercredi->setObjectName(QStringLiteral("mercredi"));

        horizontalLayout->addWidget(mercredi);

        line_2 = new QFrame(WeekCalendar);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        jeudi = new QWidget(WeekCalendar);
        jeudi->setObjectName(QStringLiteral("jeudi"));

        horizontalLayout->addWidget(jeudi);

        line_3 = new QFrame(WeekCalendar);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        vendredi = new QWidget(WeekCalendar);
        vendredi->setObjectName(QStringLiteral("vendredi"));

        horizontalLayout->addWidget(vendredi);

        line_4 = new QFrame(WeekCalendar);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        samedi = new QWidget(WeekCalendar);
        samedi->setObjectName(QStringLiteral("samedi"));

        horizontalLayout->addWidget(samedi);

        line_5 = new QFrame(WeekCalendar);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        dimanche = new QWidget(WeekCalendar);
        dimanche->setObjectName(QStringLiteral("dimanche"));

        horizontalLayout->addWidget(dimanche);


        retranslateUi(WeekCalendar);

        QMetaObject::connectSlotsByName(WeekCalendar);
    } // setupUi

    void retranslateUi(QWidget *WeekCalendar)
    {
        WeekCalendar->setWindowTitle(QApplication::translate("WeekCalendar", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class WeekCalendar: public Ui_WeekCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEEKCALENDAR_H
