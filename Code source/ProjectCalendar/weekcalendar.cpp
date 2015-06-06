#include "weekcalendar.h"
#include "ui_weekcalendar.h"

WeekCalendar::WeekCalendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeekCalendar)
{

    ui->setupUi(this);


}

WeekCalendar::~WeekCalendar()
{
    delete ui;
}
