#include "serial_setup.h"

int serialInitialize(int baud)
{
  
  if((fd=serialOpen(DEVICE,baud))<0)
    {
      fprintf(stderr, "unable to open serial %s\n", strerror(errno));
      return -1;
    }
  else
    {
      return fd;
    }
}
      
