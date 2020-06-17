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

#ifndef _MOVE_PLAYER
#define _MOVE_PLAYER
        
    #if defined(KEYBOARD_CONTROL)
        void movePlayerByKeyboard(uint8_t kbInput);
    #else // All CBM except CBM610 + ATARI + ATARI XL + ATARI 5200
        void movePlayerByJoystick(uint8_t joyInput);
    #endif

    void MOVE_PLAYER(void);
    
#endif // _MOVE_PLAYER
