#ifndef PLAYER_CONTROL_H
#define PLAYER_CONTROL_H


#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>
#include <string.h>
#include "serial_setup.h"

#define PLAY "mpc play"
#define PAUSE "mpc pause"
#define VOLUME "mpc volume %d"
#define NEXT "mpc next"
#define PREV "mpc prev"
#define STOP "mpc stop"




int distance;
int previous_distance; //must initialize in player_control.c file

char sysControl[20];

bool PLAY_PAUSE;//true=playing a song | false = when paused and/or stopped
bool PLAYER_STOPPED;//before starting a player it is stopped

/*player is initially off so PLAY_PAUSE is false and PLAYER_STOPPED is true*/

void player_control(int control_distance);
long map(long x);
void playerInit(void);


#endif
