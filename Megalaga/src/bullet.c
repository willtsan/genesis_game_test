#include "bullet.h"

#include <genesis.h>
#include <entity.h>
#include <game.h>
#include <resources.h>

Entity bullets[3];
u16 bulletsOnScreen = 0;

void BULLET_create() {
    /*Create all bullet sprites*/
    Entity* b = bullets;
    for(int i = 0; i < MAX_BULLETS; i++){
        b->x = 0;
        b->y = -10;
        b->w = 8;
        b->h = 8;
        b->sprite = SPR_addSprite(&bullet,bullets[0].x,bullets[0].y,TILE_ATTR(PAL1,0,FALSE,FALSE));
        b++;
    }
}

void BULLET_update() {
    u16 i = 0;
    Entity *b;
    for(i = 0; i < MAX_BULLETS; i++){
        b = &bullets[i];
        if(b->health > 0){

            b->y += b->vely;

            if(b->y + b->h < 0){
                ENTITY_kill(b);
                bulletsOnScreen--;
            } else{
                SPR_setPosition(b->sprite,b->x,b->y);
            }

            b->y += b->vely;
            SPR_setPosition(b->sprite,b->x,b->y);
        }
    }
}

