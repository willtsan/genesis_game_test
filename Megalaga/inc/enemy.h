#ifndef _INC_ENEMY_H_
#define _INC_ENEMY_H_

#include <genesis.h>
#include <entity.h>
#include <game.h>

extern Entity enemies[MAX_ENEMIES];
extern u16 enemiesLeft;

void ENEMIES_create();
void ENEMIES_update();
void ENEMY_destroy(Entity *e);
void ENEMIES_reset();

#endif