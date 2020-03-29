#ifndef _INC_ENTITY_H_
#define _INC_ENTITY_H_

#include <genesis.h>

typedef struct {
	int x;
	int y;
	int w;
	int h;
	int velx;
	int vely;
	int health;
	Sprite* sprite;
	char name[10];
} Entity;

void ENTITY_kill(Entity* e);
void ENTITY_revive(Entity* e);


#endif