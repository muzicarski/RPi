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

private:
    Ui::Dialog *ui;
    int VoltageVal;
    double temp;
    int light;
    QTimer * tim1;
    int fd;
};

#endif // DIALOG_H
