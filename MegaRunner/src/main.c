#include <genesis.h>
#include <string.h>
#include <resource.h>

#define ANIM_RUN	0
#define ANIM_JUMP	1

/*General stuff*/
char msg_start[22] = "Press START to Begin!";
char msg_reset[22] = "Press START to Reset!";
const int scrollspeed = 2;
bool game_on = FALSE;

Sprite* player;
const int player_x = 32;
int player_y = 112;

void showText(char s[]){
	VDP_drawText(s, 20 - strlen(s)/2 ,10);
}

void clearText(){
	VDP_clearText(0,10,32);
}

void startGame(){
	if(game_on == FALSE){
		game_on = TRUE;
		clearText();
	}
}

void endGame(){
	if(game_on == TRUE){
		showText(msg_reset);
		game_on = FALSE;
	}
}

void myJoyHandler( u16 joy, u16 changed, u16 state)
{
	if (joy == JOY_1)
	{
		/*Start game if START is pressed*/
		if (state & BUTTON_START)
		{
			if(game_on == FALSE){
				startGame();
			}
		}
		if (state & BUTTON_C)
		{
			
		}
	}
}

int main()
{
	//Input
	JOY_init();
	JOY_setEventHandler( &myJoyHandler );

	SPR_init(0,0,0);

	VDP_setPaletteColor(0,RGB24_TO_VDPCOLOR(0x6dc2ca));

	VDP_setPlanSize(32,32);

	VDP_setScrollingMode(HSCROLL_PLANE,VSCROLL_PLANE);

	VDP_loadTileSet(floor.tileset,1,DMA);
	VDP_loadTileSet(wall.tileset,2,DMA);
	VDP_loadTileSet(light.tileset,3,DMA);

	player = SPR_addSprite(&runner,player_x,player_y,TILE_ATTR(PAL2,0,FALSE,FALSE));
	SPR_setAnim(player,ANIM_RUN);

	VDP_setPalette(PAL1, light.palette->data);
	VDP_setPalette(PAL2, runner.palette->data);

	VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,16,32,1);
	VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL1,0,FALSE,TRUE,2),0,17,32,14);

	VDP_fillTileMapRectInc(PLAN_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,3),15,13,2,3);

	showText(msg_start);

	int offset = 0;
	while(1)
	{
		VDP_setHorizontalScroll(PLAN_B, offset -= scrollspeed);

		if(offset <= -256) offset = 0;

		if(game_on == TRUE){
			SPR_update();
		}
		VDP_waitVSync();
	}

	return 0;
}