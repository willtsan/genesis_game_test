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
    for(i = 0; i < MAX_ENEMIES; i++){
        Entity* e = &enemies[i];

        if(e->health > 0) {
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