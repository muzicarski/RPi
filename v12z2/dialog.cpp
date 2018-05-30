#include "dialog.h"
#include "ui_dialog.h"
#include "yl_board.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    VoltageVal = 0;
    temp = 0;
    light = 0;

    yl_init(fd);

    tim1 = new QTimer(this);
    tim1 -> start(1000);

    connect(tim1, SIGNAL(timeout()), this,SLOT(YLRead()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::YLRead(void)
{

    readYL(fd,VoltageVal,temp,light);

    ui->dial->setValue(VoltageVal);

    ui->verticalSlider->setValue(light);

    ui->lcdNumber->display(QString::number(temp));

}

