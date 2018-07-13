#ifndef SERIAL_SETUP_H
#define SERIAL_SETUP_H

#define DEVICE "/dev/ttyAMA0"

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int fd;

int serialInitialize(int);


#endif
