#include "game.h"
#include <genesis.h>

int ANIM_STRAIGHT = 0;
int ANIM_MOVE = 1;
int RIGHT_EDGE = 320;
int LEFT_EDGE = 0;

char MSG_START[22] = "Press START to Begin!";
char MSG_RESET[22] = "Press START to Reset!";
const int SCROLLSPEED = 2;
bool GAME_ON = FALSE;

void GAME_start() {
    GAME_ON = TRUE;
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