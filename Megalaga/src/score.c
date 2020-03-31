#include "score.h"

#include <genesis.h>
#include <game.h>

int score = 0;
char label_score[6] = "SCORE\0";
char str_score[3] = "0";
int score_added = 0;

void SCORE_create() {
    GAME_cleartext();

    VDP_drawText(label_score,10,1);
	score = 0;
}

void SCORE_update() {
    sprintf(str_score,"%d",score);
	VDP_clearText(1,2,3);
	VDP_drawText(str_score,10,2);
}

void SCORE_add(int value) {
    score += value;
}

void SCORE_remove(int value) {
    score -= value;
}

void SCORE_clear(int value) {
    score = 0;
}