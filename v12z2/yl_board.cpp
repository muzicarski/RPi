#include "yl_board.h"
#include <iostream>
#include <cmath>
#define PCF8591 0x48

using namespace std;

void yl_init(int &fd)
{
    wiringPiSetup();
    fd=wiringPiI2CSetup(PCF8591);
}

void readYL(int &fd, int &adc, double &t, int &light)
{
    //voltage
    double adcReg = 0;
    //light
    int lReg = 0;

    //temperature
    double tReg = 0;
    //double R6 = 0 ;
    //int B = 3950;
    //double T0 = 298.15;
    //int R0 = 10000;

    int i = 0;

    FILE * ft;
    char tekst[100];
    ft = fopen("/sys/bus/w1/devices/28-000005da8ca8/w1_slave","r");

    if (ft==NULL) return;


    for(i=0;i<22;i++)
    {
        fscanf(ft,"%s",tekst);
    }

    fclose(ft);

    for(i=0;i<10;i++) tekst[i]=tekst[i+2];
    tReg = atoi(tekst);
    t=tReg/1000;




    //read voltage
    wiringPiI2CReadReg8(fd,PCF8591+3);      //insert DELAY
    adcReg=wiringPiI2CReadReg8(fd,PCF8591+3);
    adcReg=(adcReg*100)/255;
    adc=(int)adcReg;
    //cout<<adc<<endl;


    //read Light (0 to 99)
    wiringPiI2CReadReg8(fd,PCF8591);    //insert FCKING DELAY
    lReg=wiringPiI2CReadReg8(fd,PCF8591);
    lReg =( 99-((double)lReg*100/255-1));            //vraca 255 kada nema svetla      -- invertuj slajder u .ui fajlu
   light = (int)lReg;                                //vraca 0 kada je max osvetljenje
   // cout<<light<<endl;


   /* //read temp
    wiringPiI2CReadReg8(fd,PCF8591+1);  //INSERT STUPID DELAY
    tReg = wiringPiI2CReadReg8(fd,PCF8591+1);

    //converting to celsius
    R6 = (1000*tReg)/(256-tReg);


    t=1/((1/T0)+(1/B)*log(R6/R0));
    t = t - 273.15;
    cout<<t<<endl;*/






}
