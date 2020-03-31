#include "enemy.h"

#include <genesis.h>
#include <game.h>
#include <entity.h>
#include <resources.h>
#include <bullet.h>
#include <collision.h>
#include <score.h>

Entity enemies[MAX_ENEMIES];
u16 enemiesLeft = 0;


void ENEMIES_create() {
    Entity* e = enemies;
    for(int i = 0; i < MAX_ENEMIES; i++){
        e->x = i*32;
        e->y = 32;
        e->w = 16;
        e->h = 16;
        e->velx = 1;
        e->health = 1;
        e->sprite = SPR_addSprite(&ship,e->x,e->y,TILE_ATTR(PAL2,0,TRUE,FALSE));
        //sprintf(e->name, "En%d",i);
        enemiesLeft++;
        e++;
    }
    VDP_setPaletteColor(34,RGB24_TO_VDPCOLOR(0x0078f8));
}

void ENEMIES_update() {
    u16 i = 0;
    Entity *b;
    for(i = 0; i < MAX_ENEMIES; i++){
        Entity* e = &enemies[i];

        if(e->health > 0) {

            for(u16 j = 0; j < MAX_BULLETS; j++) {
                b = &bullets[j];
                if(b->health > 0) {
                    if(COLLISION_overlap(e, b)) {
                        ENEMY_destroy(e);
                        BULLET_destroy(b);
                    }
                }
            }

            if( (e->x+e->w) > RIGHT_EDGE){
                e->velx = -1;
            }
            else if(e->x < LEFT_EDGE){
                e->velx = 1;
            }

            e->x += e->velx;
            SPR_setPosition(e->sprite,e->x,e->y);
        }        
    }
}

void ENEMY_destroy(Entity *e) {
    e->health = 0;
    ENTITY_kill(e);

    SCORE_add(1);

    if (enemiesLeft - 1 <= 0) {
        GAME_end();
    }
    else {
        enemiesLeft--;
    }
}

void ENEMIES_reset() {
    enemiesLeft = MAX_ENEMIES;

    u16 i = 0;
    for(i = 0; i < MAX_ENEMIES; i++){
        Entity* e = &enemies[i];
        ENTITY_revive(e);
        e->x = i*32;
        e->y = 32;
        e->w = 16;
        e->h = 16;
        e->velx = 1;
        e->health = 1;
    }
}