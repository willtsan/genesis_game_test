#ifndef _INC_BULLET_H_
#define _INC_BULLET_H_

#include <genesis.h>
#include <entity.h>
#include <game.h>

extern u16 bulletsOnScreen;
extern Entity bullets[MAX_BULLETS];

void BULLET_create();
void BULLET_update();
void BULLET_destroy(Entity *b);
void BULLETS_reset();

#endif 