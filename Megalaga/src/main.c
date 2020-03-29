#include <genesis.h>
#include <resources.h>
#include <game.h>

#include <entity.h>

#include <background.h>
#include <score.h>
#include <player.h>
#include <bullet.h>
#include <enemy.h>

void myJoyHandler( u16 joy, u16 changed, u16 state)
{
	if (joy == JOY_1)
	{
		if(state & BUTTON_START) {
			if (GAME_ON == FALSE) {
				GAME_start();
			}
		}
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
		if(GAME_ON == TRUE) {
			BACKGROUND_update();
			BULLET_update();
			PLAYER_update();
			ENEMIES_update();
			SPR_update();
		} else {
			GAME_showtext(MSG_START);
			SPR_clear();
		}

		VDP_waitVSync();
	}
	return (0);
}


