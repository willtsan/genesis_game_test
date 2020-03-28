#include <genesis.h>
#include <resources.h>

// BACKGROUND
int i = 0;
int thex = 0;
int they = 0;
int val = 1;

int offset = 0;

void BACKGROUND_create() {
    VDP_loadTileSet(background.tileset,1,DMA);
	VDP_setPalette(PAL1, background.palette->data);
	VDP_setPalette(PAL2, background.palette->data);

	for( i=0; i < 1280; i++){
		thex = i % 40;
		they = i / 40;
		val = (random() %  (10-1+1))+1;
		if(val > 3) val = 1;
		VDP_setTileMapXY(PLAN_B,TILE_ATTR_FULL(PAL1,0,0,0,val), thex, they );
	}

	VDP_setScrollingMode(HSCROLL_PLANE,VSCROLL_PLANE);
}

void BACKGROUND_update() {
	VDP_setVerticalScroll(PLAN_B,offset -= 2);
	if(offset >= 256) offset = 0;
}