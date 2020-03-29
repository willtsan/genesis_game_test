#ifndef _INC_PLAYER_H_
#define _INC_PLAYER_H_

#include <genesis.h>
#include <entity.h>

Entity player;



void PLAYER_create();
void PLAYER_input(u16 joy, u16 changed, u16 state);
void PLAYER_shoot();
void PLAYER_update();

#endif