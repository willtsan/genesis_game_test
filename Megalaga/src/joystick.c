#include "joystick.h";

#include <genesis.h>
#include <game.h>
#include <player.h>

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