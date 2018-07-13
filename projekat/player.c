#include <stdio.h>
#include "player_control.h"

int rLen;
char rBuff[10];
char received_char;
int converted_distance=0;


int main()
{

  int i=0;
  int baudrate =9600;
  

  if( serialInitialize(baudrate)<0)
    {
      return 1;
    }

  playerInit();

  
  while(1)
    {

      if(rLen=serialDataAvail(fd))
	{
	  delay(100);
	  while(rLen!=0)
	    {
	      //printf("got something");//DEBUG LINE
	      received_char=serialGetchar(fd);
	      rBuff[i]=received_char;
	      i++;
	      rLen--;
	    }
	  i=0;
	  converted_distance=atoi(rBuff);
	  serialFlush(fd);
	  //printf("converted distance %d\n",converted_distance);// DEBUG LINE
	  player_control(converted_distance);
	  serialFlush(fd);
	}
      else
	{
	  delay(100);
	}
      
    }

   
  return 0;
}
