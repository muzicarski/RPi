#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>

#define YL 0x48

int main()
{
  int fd;
  int voltage;
  int light;

  wiringPiSetup();
  fd = wiringPiI2CSetup(YL);
  

  while(1)
    {
      wiringPiI2CReadReg8(fd,YL+3);      //insert DELAY
      voltage=wiringPiI2CReadReg8(fd,YL+3);
      printf("voltage %d\n",voltage);

      delay(500);
      wiringPiI2CReadReg8(fd, YL);
      light = wiringPiI2CReadReg8(fd, YL);
      printf("light %d\n",light);
      delay(500);
    }
  return 0;
}
