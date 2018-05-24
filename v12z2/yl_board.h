#ifndef YL_BOARD_H
#define YL_BOARD_H

#include <wiringPi.h>
#include <wiringPiI2C.h>

void yl_init(int &fd);

void readYL(int &fd, double &adc, double &t, double &light);

#endif // YL_BOARD_H
