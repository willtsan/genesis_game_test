#include "game.h"
#include <genesis.h>

int ANIM_STRAIGHT = 0;
int ANIM_MOVE = 1;
int MAX_BULLETS = 3;
int RIGHT_EDGE = 320;
int LEFT_EDGE = 0;
int MAX_ENEMIES = 6;

char MSG_START[22] = "Press START to Begin!";
char MSG_RESET[22] = "Press START to Reset!";
const int SCROLLSPEED = 2;
int GAME_ON = 0;

void GAME_start() {
    GAME_ON = 1;
    GAME_cleartext();
}

void GAME_end() {

}

void GAME_showtext(char s[]) {
	VDP_drawText(s, 20 - strlen(s)/2 ,10);
}

void GAME_cleartext() {
	VDP_clearText(0,10,32);
}