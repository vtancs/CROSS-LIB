/* --------------------------------------------------------------------------------------- */ 
// 
// CROSS SHOOT by Fabrizio Caruso
//
// Fabrizio_Caruso@hotmail.com
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.

// Permission is granted to anyone to use this software for non-commercial applications, 
// subject to the following restrictions:

// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software in
// a product, an acknowledgment in the product documentation would be
// appreciated but is not required.

// 2. Altered source versions must be plainly marked as such, and must not
// be misrepresented as being the original software.

// 3. This notice may not be removed or altered from any source distribution.
/* --------------------------------------------------------------------------------------- */ 


#if !defined EXIT_SUCCESS
    #define EXIT_SUCCESS 0
#endif

// TODO: REMOVE THIS
#define DEBUG_ITEMS


// #include "images.h"
#include "cross_lib.h"

#include "init_images.h"
extern Image WALL_1_IMAGE;
extern Image WALL_2_IMAGE;

extern Image TWO_WINDOW_WALL_1_IMAGE;
extern Image TWO_WINDOW_WALL_2_IMAGE;

extern Image THREE_WINDOW_WALL_1_IMAGE;
extern Image THREE_WINDOW_WALL_2_IMAGE;

extern Image SMALL_TWO_WINDOW_WALL_1_IMAGE;
extern Image SMALL_TWO_WINDOW_WALL_2_IMAGE;

#define BUILDINGS_NUMBER (XSize-9)
#define FIRST_BULDING_X_POS 5
uint16_t bulding_height[XSize];

int main(void)
{        
    uint8_t i;
    uint8_t j;
    uint8_t r;
    Image *buildingTypePtr;

    INIT_GRAPHICS();

    INIT_INPUT();

    
    while(1)
    {

        INIT_IMAGES();
        
        CLEAR_SCREEN();
        
        SET_TEXT_COLOR(COLOR_WHITE);
        // This should be handled throw generic CAPITAL_CASE_ONLY, SMALL_CASE_ONLY, ALL_CASES macros
        #if defined(__LCC1802__)
            PRINT(4,0,"PRESS FIRE");
        #else
            PRINT(4,0,"press fire");
        #endif
        WAIT_PRESS();
        
        for(i=FIRST_BULDING_X_POS;i<FIRST_BULDING_X_POS+BUILDINGS_NUMBER;++i)
        {
            bulding_height[i] = (uint8_t) 4+(rand()&15);
            // PRINTD(2,2,2,0);WAIT_PRESS();PRINTD(2,2,2,bulding_height[i]); SLEEP(1);WAIT_PRESS();
            r = rand()&7;
            if(r==0)
            {
                buildingTypePtr = &WALL_1_IMAGE;
            }
            else if(r==1)
            {
                buildingTypePtr = &WALL_2_IMAGE;
            }
            else if(r==3)
            {
                buildingTypePtr = &TWO_WINDOW_WALL_1_IMAGE;
            }
            else if(r==3)
            {
                buildingTypePtr = &TWO_WINDOW_WALL_1_IMAGE;
            }
            else if(r==4)
            {
                buildingTypePtr = &THREE_WINDOW_WALL_1_IMAGE;
            }
            else if(r==5)
            {
                buildingTypePtr = &THREE_WINDOW_WALL_2_IMAGE;
            }
            else if(r==6)
            {
                buildingTypePtr = &SMALL_TWO_WINDOW_WALL_1_IMAGE;
            }
            else if(r==7)
            {
                buildingTypePtr = &SMALL_TWO_WINDOW_WALL_2_IMAGE;
            }
            
            for(j=0;j<bulding_height[i];++j)
            {
                _XLIB_DRAW(i,YSize-1-j,buildingTypePtr);
                TOCK_SOUND();
            }
            PING_SOUND();
        }
        SLEEP(1);
        WAIT_PRESS();
    } // while(1) -> restart from the beginning

    return EXIT_SUCCESS;
}
