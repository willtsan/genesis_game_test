#include "entity.h"

void ENTITY_kill(Entity* e){
	e->health = 0;
	SPR_setVisibility(e->sprite,HIDDEN);
}

void ENTITY_revive(Entity* e){
	e->health = 1;
	SPR_setVisibility(e->sprite,VISIBLE);
}