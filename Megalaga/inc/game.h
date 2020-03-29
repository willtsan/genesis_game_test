#ifndef _INC_GAME_H_
#define _INC_GAME_H_

#include <genesis.h>

extern int ANIM_STRAIGHT;
extern int ANIM_MOVE;
extern const int MAX_ENEMIES;
extern int RIGHT_EDGE;
extern int LEFT_EDGE;
extern int MAX_BULLETS;

extern char MSG_START[22];
extern char MSG_RESET[22];
extern const int SCROLLSPEED;
extern bool GAME_ON;

void GAME_start();
void GAME_end();
void GAME_showtext(char s[]);
void GAME_cleartext();

#endif