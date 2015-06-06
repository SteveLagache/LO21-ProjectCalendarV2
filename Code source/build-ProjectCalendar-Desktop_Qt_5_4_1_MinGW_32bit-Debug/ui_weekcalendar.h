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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeekCalendar
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *MainBox;
    QVBoxLayout *calendrierTop;
    QHBoxLayout *jours;
    QSpinBox *spinBox;
    QHBoxLayout *gestionSemaine;
    QLabel *label_lundi;
    QFrame *line_8;
    QLabel *label_mardi;
    QFrame *line_9;
    QLabel *label_mercredi;
    QFrame *line_10;
    QLabel *label_jeudi;
    QFrame *line_11;
    QLabel *label_vendredi;
    QFrame *line_7;
    QLabel *label_samedi;
    QFrame *line_12;
    QLabel *label_dimanche;
    QHBoxLayout *vueCalendrier1;
    QWidget *vueCalendrier2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *lundi;
    QPushButton *pushButton;
    QFrame *line;
    QWidget *mardi;
    QPushButton *pushButton_2;
    QFrame *line_2;
    QWidget *mercredi;
    QFrame *line_3;
    QWidget *jeudi;
    QFrame *line_4;
    QWidget *vendredi;
    QFrame *line_5;
    QWidget *samedi;
    QFrame *line_6;
    QWidget *dimanche;
    QHBoxLayout *calendrierBottom;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QWidget *WeekCalendar)
    {
        if (WeekCalendar->objectName().isEmpty())
            WeekCalendar->setObjectName(QStringLiteral("WeekCalendar"));
        WeekCalendar->resize(1130, 628);
        WeekCalendar->setMinimumSize(QSize(500, 0));
        verticalLayout_3 = new QVBoxLayout(WeekCalendar);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        MainBox = new QVBoxLayout();
        MainBox->setObjectName(QStringLiteral("MainBox"));
        calendrierTop = new QVBoxLayout();
        calendrierTop->setObjectName(QStringLiteral("calendrierTop"));
        jours = new QHBoxLayout();
        jours->setObjectName(QStringLiteral("jours"));
        spinBox = new QSpinBox(WeekCalendar);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        jours->addWidget(spinBox);


        calendrierTop->addLayout(jours);

        gestionSemaine = new QHBoxLayout();
        gestionSemaine->setObjectName(QStringLiteral("gestionSemaine"));
        label_lundi = new QLabel(WeekCalendar);
        label_lundi->setObjectName(QStringLiteral("label_lundi"));
        label_lundi->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_lundi->setFont(font);
        label_lundi->setFrameShape(QFrame::NoFrame);
        label_lundi->setTextFormat(Qt::AutoText);
        label_lundi->setAlignment(Qt::AlignCenter);

        gestionSemaine->addWidget(label_lundi);

        line_8 = new QFrame(WeekCalendar);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gestionSemaine->addWidget(line_8);

        label_mardi = new QLabel(WeekCalendar);
        label_mardi->setObjectName(QStringLiteral("label_mardi"));
        label_mardi->setMaximumSize(QSize(16777215, 30));
        label_mardi->setFont(font);
        label_mardi->setFrameShape(QFrame::NoFrame);
        label_mardi->setTextFormat(Qt::AutoText);
        label_mardi->setAlignment(Qt::AlignCenter);

        gestionSemaine->addWidget(label_mardi);

        line_9 = new QFrame(WeekCalendar);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gestionSemaine->addWidget(line_9);

        label_mercredi = new QLabel(WeekCalendar);
        label_mercredi->setObjectName(QStringLiteral("label_mercredi"));
        label_mercredi->setMaximumSize(QSize(16777215, 30));
        label_mercredi->setFont(font);
        label_mercredi->setFrameShape(QFrame::NoFrame);
        label_mercredi->setTextFormat(Qt::AutoText);
        label_mercredi->setAlignment(Qt::AlignCenter);

        gestionSemaine->addWidget(label_mercredi);

        line_10 = new QFrame(WeekCalendar);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gestionSemaine->addWidget(line_10);

        label_jeudi = new QLabel(WeekCalendar);
        label_jeudi->setObjectName(QStringLiteral("label_jeudi"));
        label_jeudi->setMaximumSize(QSize(16777215, 30));
        label_jeudi->setFont(font);
        label_jeudi->setFrameShape(QFrame::NoFrame);
        label_jeudi->setTextFormat(Qt::AutoText);
        label_jeudi->setAlignment(Qt::AlignCenter);

        gestionSemaine->addWidget(label_jeudi);

        line_11 = new QFrame(WeekCalendar);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gestionSemaine->addWidget(line_11);

        label_vendredi = new QLabel(WeekCalendar);
        label_vendredi->setObjectName(QStringLiteral("label_vendredi"));
        label_vendredi->setMaximumSize(QSize(16777215, 30));
        label_vendredi->setFont(font);
        label_vendredi->setFrameShape(QFrame::NoFrame);
        label_vendredi->setTextFormat(Qt::AutoText);
        label_vendredi->setAlignment(Qt::AlignCenter);

        gestionSemaine->addWidget(label_vendredi);

        line_7 = new QFrame(WeekCalendar);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gestionSemaine->addWidget(line_7);

        label_samedi = new QLabel(WeekCalendar);
        label_samedi->setObjectName(QStringLiteral("label_samedi"));
        label_samedi->setMaximumSize(QSize(16777215, 30));
        label_samedi->setFont(font);
        label_samedi->setFrameShape(QFrame::NoFrame);
        label_samedi->setTextFormat(Qt::AutoText);
        label_samedi->setAlignment(Qt::AlignCenter);

        gestionSemaine->addWidget(label_samedi);

        line_12 = new QFrame(WeekCalendar);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gestionSemaine->addWidget(line_12);

        label_dimanche = new QLabel(WeekCalendar);
        label_dimanche->setObjectName(QStringLiteral("label_dimanche"));
        label_dimanche->setMaximumSize(QSize(16777215, 30));
        label_dimanche->setFont(font);
        label_dimanche->setFrameShape(QFrame::NoFrame);
        label_dimanche->setTextFormat(Qt::AutoText);
        label_dimanche->setAlignment(Qt::AlignCenter);

        gestionSemaine->addWidget(label_dimanche);


        calendrierTop->addLayout(gestionSemaine);


        MainBox->addLayout(calendrierTop);

        vueCalendrier1 = new QHBoxLayout();
        vueCalendrier1->setObjectName(QStringLiteral("vueCalendrier1"));
        vueCalendrier2 = new QWidget(WeekCalendar);
        vueCalendrier2->setObjectName(QStringLiteral("vueCalendrier2"));
        vueCalendrier2->setMinimumSize(QSize(40, 400));
        horizontalLayout_2 = new QHBoxLayout(vueCalendrier2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lundi = new QWidget(vueCalendrier2);
        lundi->setObjectName(QStringLiteral("lundi"));
        lundi->setMinimumSize(QSize(40, 0));
        pushButton = new QPushButton(lundi);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 112, 61));
        pushButton->setMinimumSize(QSize(40, 0));

        horizontalLayout_2->addWidget(lundi);

        line = new QFrame(vueCalendrier2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        mardi = new QWidget(vueCalendrier2);
        mardi->setObjectName(QStringLiteral("mardi"));
        mardi->setMinimumSize(QSize(40, 0));
        pushButton_2 = new QPushButton(mardi);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 121, 151));
        pushButton_2->setMinimumSize(QSize(40, 0));

        horizontalLayout_2->addWidget(mardi);

        line_2 = new QFrame(vueCalendrier2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        mercredi = new QWidget(vueCalendrier2);
        mercredi->setObjectName(QStringLiteral("mercredi"));
        mercredi->setMinimumSize(QSize(40, 0));

        horizontalLayout_2->addWidget(mercredi);

        line_3 = new QFrame(vueCalendrier2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        jeudi = new QWidget(vueCalendrier2);
        jeudi->setObjectName(QStringLiteral("jeudi"));
        jeudi->setMinimumSize(QSize(50, 0));

        horizontalLayout_2->addWidget(jeudi);

        line_4 = new QFrame(vueCalendrier2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_4);

        vendredi = new QWidget(vueCalendrier2);
        vendredi->setObjectName(QStringLiteral("vendredi"));
        vendredi->setMinimumSize(QSize(40, 0));

        horizontalLayout_2->addWidget(vendredi);

        line_5 = new QFrame(vueCalendrier2);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_5);

        samedi = new QWidget(vueCalendrier2);
        samedi->setObjectName(QStringLiteral("samedi"));
        samedi->setMinimumSize(QSize(40, 0));

        horizontalLayout_2->addWidget(samedi);

        line_6 = new QFrame(vueCalendrier2);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_6);

        dimanche = new QWidget(vueCalendrier2);
        dimanche->setObjectName(QStringLiteral("dimanche"));
        dimanche->setMinimumSize(QSize(40, 0));

        horizontalLayout_2->addWidget(dimanche);


        vueCalendrier1->addWidget(vueCalendrier2);


        MainBox->addLayout(vueCalendrier1);

        calendrierBottom = new QHBoxLayout();
        calendrierBottom->setObjectName(QStringLiteral("calendrierBottom"));
        pushButton_4 = new QPushButton(WeekCalendar);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        calendrierBottom->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(WeekCalendar);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        calendrierBottom->addWidget(pushButton_3);


        MainBox->addLayout(calendrierBottom);


        verticalLayout_3->addLayout(MainBox);


        retranslateUi(WeekCalendar);

        QMetaObject::connectSlotsByName(WeekCalendar);
    } // setupUi

    void retranslateUi(QWidget *WeekCalendar)
    {
        WeekCalendar->setWindowTitle(QApplication::translate("WeekCalendar", "Form", 0));
        label_lundi->setText(QApplication::translate("WeekCalendar", "Lundi", 0));
        label_mardi->setText(QApplication::translate("WeekCalendar", "Mardi", 0));
        label_mercredi->setText(QApplication::translate("WeekCalendar", "Mercredi", 0));
        label_jeudi->setText(QApplication::translate("WeekCalendar", "Jeudi", 0));
        label_vendredi->setText(QApplication::translate("WeekCalendar", "Vendredi", 0));
        label_samedi->setText(QApplication::translate("WeekCalendar", "Samedi", 0));
        label_dimanche->setText(QApplication::translate("WeekCalendar", "Dimanche", 0));
        pushButton->setText(QApplication::translate("WeekCalendar", "Test2", 0));
        pushButton_2->setText(QApplication::translate("WeekCalendar", "Test1", 0));
        pushButton_4->setText(QApplication::translate("WeekCalendar", "Ajouter \303\251v\303\250nement", 0));
        pushButton_3->setText(QApplication::translate("WeekCalendar", "Blabla", 0));
    } // retranslateUi

};

namespace Ui {
    class WeekCalendar: public Ui_WeekCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEEKCALENDAR_H
