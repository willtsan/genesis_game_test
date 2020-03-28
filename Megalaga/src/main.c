#include <genesis.h>
#include <resources.h>
#include <system_vars.h>

#include <game/entities/entity.c>

#include <game/background/background.c>
#include <game/entities/bullet/bullet.c>
#include <game/entities/player/player.c>
#include <game/entities/enemy/enemy.c>

void myJoyHandler( u16 joy, u16 changed, u16 state)
{
	if (joy == JOY_1)
	{
		PLAYER_input(joy, changed, state);
	}
}

int main()
{
	SYS_disableInts();

	SPR_init();
	JOY_init();
	
	BACKGROUND_create();
	BULLET_create();
	PLAYER_create();
	ENEMIES_create();

	JOY_setEventHandler( &myJoyHandler );
	
	SYS_enableInts();
	
	while(1)
	{  		
		BACKGROUND_update();
		BULLET_update();
		PLAYER_update();
		ENEMIES_update();

		SPR_update();
		VDP_waitVSync();
	}
	return (0);
}


