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

/*void Dialog::on_pushButton_clicked()                      //DEBUG TOOLS
{
    bool ok;
    VoltageVal = (ui->lineEdit->text()).toInt(&ok,10);

    ui->dial->setValue(VoltageVal);
}

void Dialog::on_pushButton_2_clicked()
{
    bool ok;
    light = (ui->lineEdit_2->text()).toInt(&ok,10);

    ui->verticalSlider->setValue(light);
}

void Dialog::on_pushButton_3_clicked()
{
    bool ok;
    temp = (ui->lineEdit_3->text()).toDouble(&ok);

    ui->lcdNumber->display(QString::number(temp));


}*/
