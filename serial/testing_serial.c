#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <errno.h>
#include <string.h>


void writeSketch(void);     //write function test
void readCharSketch(void);  //getChar and available data test

int fd;    //file descriptor
int rLen;


char received_char;

int main()
{

  if((fd=serialOpen("/dev/ttyAMA0",9600))<0)
    {

      fprintf(stderr, "unable to open serial %s\n", strerror(errno));
      return 1;

    }

  printf("Opened serial device: %d\n",fd);



  while(1)
    {
      //      writeSketch();
      readCharSketch();
    }

  
  serialClose(fd);
  
  return 0;
}




/****************************************************************
FUNCTION IMPLEMENTATIONS
*****************************************************************/



void writeSketch(void)
{
 
  serialPutchar(fd,'c');
  delay(1000);
  /*  serialPuts(fd,"serial_puts_test");
  delay(1000);
  serialPrintf(fd,"serial_PRINTF_test");
  delay(4000);*/
}

void readCharSketch(void)
{
  /*this func test to see if once read, character dissapears from read buffer */


  if(rLen=serialDataAvail(fd))
    {
      
      while(rLen!=1)
	{
	  received_char=serialGetchar(fd);
	  printf("%c",received_char);
	  rLen--;
	}
	 
      serialFlush(fd);

      printf("\n");
    }
	
  delay(100);

  
}
