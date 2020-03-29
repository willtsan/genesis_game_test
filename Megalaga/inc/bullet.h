#ifndef _INC_BULLET_H_
#define _INC_BULLET_H_

#include <genesis.h>
#include <entity.h>

extern u16 bulletsOnScreen;
extern Entity bullets[3];

void BULLET_create();
void BULLET_update();

#endif 