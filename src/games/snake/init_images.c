#include "display_macros.h"

#include "tiles.h"

#include "init_images.h"


Image VERTICAL_HEAD_IMAGE;  
Image HORIZONTAL_HEAD_IMAGE; 

Image BODY_IMAGE; 

Image EXTRA_POINTS_IMAGE; 

Image HORIZONTAL_BRICK_IMAGE;
Image VERTICAL_BRICK_IMAGE;

Image SCORE_TEXT_LEFT_IMAGE;
Image SCORE_TEXT_RIGHT_IMAGE;
Image HI_TEXT_IMAGE;
Image LV_TEXT_IMAGE;

Image APPLE_IMAGE;

void INIT_IMAGES(void)
{
	// Set color data 
	#if !defined(NO_COLOR)

        VERTICAL_HEAD_IMAGE._color = _SNAKE_COLOR;
        HORIZONTAL_HEAD_IMAGE._color = _SNAKE_COLOR;

        BODY_IMAGE._color = _SNAKE_COLOR;

        EXTRA_POINTS_IMAGE._color = COLOR_YELLOW;
        
        VERTICAL_BRICK_IMAGE._color = _WALL_COLOR;
        HORIZONTAL_BRICK_IMAGE._color = _WALL_COLOR;
        
        SCORE_TEXT_LEFT_IMAGE._color = COLOR_CYAN;
        SCORE_TEXT_RIGHT_IMAGE._color = COLOR_CYAN;
        
        HI_TEXT_IMAGE._color = COLOR_RED;;
        LV_TEXT_IMAGE._color = COLOR_GREEN;
        
        APPLE_IMAGE._color = COLOR_RED;
	#endif	

	// Set Image Data
    VERTICAL_HEAD_IMAGE._imageData = _TILE_0;
    HORIZONTAL_HEAD_IMAGE._imageData = _TILE_1;

    BODY_IMAGE._imageData = _TILE_4;
    APPLE_IMAGE._imageData = _TILE_5;

    EXTRA_POINTS_IMAGE._imageData = _DOLLAR_TILE;

    VERTICAL_BRICK_IMAGE._imageData = _TILE_12;
    HORIZONTAL_BRICK_IMAGE._imageData = _TILE_13;

    SCORE_TEXT_LEFT_IMAGE._imageData = _TILE_14;
    SCORE_TEXT_RIGHT_IMAGE._imageData = _TILE_16;
    HI_TEXT_IMAGE._imageData = _TILE_6;;
    LV_TEXT_IMAGE._imageData = _TILE_9;
}


