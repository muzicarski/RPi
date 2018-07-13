#include "player_control.h"




void player_control (int control_distance)
{
  int music_volume = 0;
  distance=control_distance;
  if(PLAYER_STOPPED)
    {
      if(distance>=2 && distance <=10)
	{
	  PLAYER_STOPPED = false;
	  PLAY_PAUSE = true;
	  system(PLAY);
	  delay(1000);
	}
    }
  else if((!PLAYER_STOPPED)&&(previous_distance!=distance))
    {
      if(distance > 10 && distance <=45)
	{
	  music_volume =(int) map((long)distance);
	  sprintf(sysControl,VOLUME,music_volume);
	  system(sysControl);
	  delay(200);
	}
      else if(distance >= 60 && distance <=65)
	{
	  system(NEXT);
	  delay(1000);
	}
      else if(distance >=75 && distance <80)
	{
	  system(PREV);
	  delay(1000);
	}
      else if(distance >90 && distance <100)
	{
	  system(STOP);
	  PLAYER_STOPPED = true;
	  PLAY_PAUSE = false;
	  delay(1000);
	}
      else if(distance >=2 && distance <=10)
	{
	  if(PLAY_PAUSE)
	    system(PAUSE);
	  else
	    system(PLAY);

	  PLAY_PAUSE=!PLAY_PAUSE;

	  delay(1000);
	}
      
    }
  previous_distance = distance;
	     
  
}



long map(long x)
{
  long in_min = 10;
  long in_max = 45;
  long out_max = 100;
  long out_min = 0;


  return (x-in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    
}


void playerInit(void)
{
  PLAY_PAUSE = false;
  PLAYER_STOPPED = true;
  system("mpc repeat on");
  
  distance = 0;
  previous_distance = 0;
}
