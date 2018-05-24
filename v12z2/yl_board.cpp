#include "yl_board.h"
#include <iostream>
#define PCF8591 0x48

using namespace std;

void yl_init(int &fd)
{
    wiringPiSetup();
    fd=wiringPiI2CSetup(PCF8591);
}

void readYL(int &fd, double &adc, double &t, double &light)
{
    int adcReg = 0;
    int tReg = 0;
    int lReg = 0;

    //read voltage
    adcReg=wiringPiI2CReadReg8(fd,PCF8591+3);
    adc=(double)adcReg*3.3/255;

    //read Light (0 to 99)
    lReg=wiringPiI2CReadReg8(fd,PCF8591);
    light = 99-((double)lReg*100/255-1);            //vraca 255 kada nema svetla      -- invertuj slajder u .ui fajlu
                                             //vraca 0 kada je max osvetljenje
    //read temp
    tReg = wiringPiI2CReadReg8(fd,PCF8591+1);
    t=double(tReg);
    cout<<t<<endl;
}
