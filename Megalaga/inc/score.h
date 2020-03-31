#ifndef _INC_SCORE_H_
#define _INC_SCORE_H_

extern int score;
extern char label_score[6];
extern char str_score[3];
extern int score_added;

void SCORE_create();
void SCORE_update();
void SCORE_add(int value);
void SCORE_remove(int value);
void SCORE_clear(int value);

#endif