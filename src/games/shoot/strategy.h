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
 
#ifndef _STRATEGY
#define _STRATEGY


#define X_MOVE 0
#define Y_MOVE 1

#if defined(__CMOC__) && !defined(__WINCMOC__)
    #include <cmoc.h>
#else
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
#endif

#include "character.h"

uint8_t innerWallBetween(Character *prePtr, Character *hunterPtr);

// Required by horizontal missile
uint8_t moveCharacter(uint8_t *hunterOffsetPtr, uint8_t *preyOffsetPtr);

#if !defined(SIMPLE_STRATEGY)
    void blindChaseCharacterXStrategy(Character* hunterPtr, Character* preyPtr);
    void blindChaseCharacterYStrategy(Character* hunterPtr, Character* preyPtr);
#endif

#if !defined(SIMPLE_STRATEGY)
    void moveTowardCharacter(Character *preyPtr, Character *hunterPtr, uint8_t strategy);
#else 
    void moveTowardCharacter(Character *preyPtr, Character *hunterPtr);
#endif

void skullMoveTowardCharacter(Character *preyPtr, Character *hunterPtr, uint8_t strategy);


#if !defined(SIMPLE_STRATEGY)
    void computeStrategy(void);
#endif


void chaseCharacter(Character *preyPtr, uint16_t slowDown);    

    
#endif // _STRATEGY

