Entity player = {
    0, 
    0, 
    16, 
    16, 
    0, 
    0, 
    0, 
    0, 
    "PLAYER"};

void PLAYER_create() {
    player.x = 152;
    player.y = 192;
    player.health = 1;
    player.sprite = SPR_addSprite(&ship,player.x,player.y,TILE_ATTR(PAL1,0,FALSE,FALSE));
}

void PLAYER_input(u16 joy, u16 changed, u16 state) {
    if (joy == JOY_1)
    {
        if (state & BUTTON_RIGHT)
	    {
            player.velx = 2;
            SPR_setAnim(player.sprite,ANIM_MOVE);
            SPR_setHFlip(player.sprite,TRUE);
        }
        else if (state & BUTTON_LEFT)
        {
            player.velx = -2;
            SPR_setAnim(player.sprite,ANIM_MOVE);
            SPR_setHFlip(player.sprite,FALSE);
        }
        else{
            if( (changed & BUTTON_RIGHT) | (changed & BUTTON_LEFT) ){
                player.velx = 0;
                SPR_setAnim(player.sprite,ANIM_STRAIGHT);
            }
        }

        if (state & BUTTON_B & changed)
        {
            PLAYER_shoot();
        }
    }
}

void PLAYER_shoot(){
    if( bulletsOnScreen < MAX_BULLETS ){
        Entity* b;
        u16 i = 0;
        for(i=0; i<MAX_BULLETS; i++){
            b = &bullets[i];
            if(b->health == 0){

                b->x = player.x+4;
                b->y = player.y;

                ENTITY_revive(b);
                b->vely = -3;

                SPR_setPosition(b->sprite,b->x,b->y);
                bulletsOnScreen++;
                break;
            }
        }	
    }
}

void PLAYER_update() {
    /*Add the player's velocity to its position*/
    player.x += player.velx;

    /*Keep the player within the bounds of the screen*/
    if(player.x < LEFT_EDGE) player.x = LEFT_EDGE;
    if(player.x + player.w > RIGHT_EDGE) player.x = RIGHT_EDGE - player.w;

    /*Let the Sprite engine position the sprite*/
    SPR_setPosition(player.sprite,player.x,player.y);
}