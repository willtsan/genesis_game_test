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

void ENTITY_kill(Entity* e){
	e->health = 0;
	SPR_setVisibility(e->sprite,HIDDEN);
}

void ENTITY_revive(Entity* e){
	e->health = 1;
	SPR_setVisibility(e->sprite,VISIBLE);
}