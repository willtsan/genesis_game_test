#define MAX_ENEMIES 6
#define LEFT_EDGE 0
#define RIGHT_EDGE 320

#define ANIM_STRAIGHT 0
#define ANIM_MOVE 1

#define MAX_BULLETS	3

char msg_start[22] = "Press START to Begin!";
char msg_reset[22] = "Press START to Reset!";
const int scrollspeed = 2;
bool game_on = FALSE;

void GAME_start() {
    game_on = TRUE;
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