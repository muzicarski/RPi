#ifndef YL_BOARD_H
#define YL_BOARD_H

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdlib.h>
#include <stdio.h>

void yl_init(int &fd);

void readYL(int &fd, int &adc, double &t, int &light);

#endif // YL_BOARD_H
