#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void YLRead(void);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
    int VoltageVal;
    double temp;
    int light;
    QTimer * tim1;
    int fd;
};

#endif // DIALOG_H
