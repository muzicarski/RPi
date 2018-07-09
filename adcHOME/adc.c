#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <math.h>


#define YL 0x48

double toCelsius(int temp);


int main()
{
  int fd;
  int voltage;
  int light;
  int temp;
  double temperature;
  wiringPiSetup();
  fd = wiringPiI2CSetup(YL);
  

  while(1)
    {
      wiringPiI2CReadReg8(fd,YL+3);      //insert DELAY
      voltage=wiringPiI2CReadReg8(fd,YL+3);


      delay(500);
      wiringPiI2CReadReg8(fd, YL+2);
      temp = wiringPiI2CReadReg8(fd, YL+2);
      temperature=toCelsius(temp);

      delay(500);
      wiringPiI2CReadReg8(fd, YL);
      light = wiringPiI2CReadReg8(fd, YL);
      printf("voltage %d\n",voltage);
      printf("temp %f\n",temperature);
      printf("light %d\n",light);
      printf("---------\n");
      delay(1000);

    }
  return 0;
}

double toCelsius(int temp)
{
  double R1=1000;
  double R6;
  double R0=10000;
  double B = 3950;//clamied from adafruit.com
  double a= (double)temp;
  double T;
  double T0=298.15;
  double t0=1;
  double r,l;
  R6=(R1*a)/(256-a);
  r=R6/R0;

  l=log(r);

  t0=(1/T0)+(1/B)*l;

  T0=1/t0;

  return(T0-273.15);
}
