#include "projectcalendar.h"
#include "weekcalendar.h"
#include "ui_projectcalendar.h"

ProjectCalendar::ProjectCalendar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProjectCalendar)
{
    ui->setupUi(this);
    semaine= new WeekCalendar(centralWidget());
    centralWidget()->layout()->addWidget(semaine);
}

ProjectCalendar::~ProjectCalendar()
{
    delete ui;
}
