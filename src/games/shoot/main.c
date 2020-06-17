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

#if defined(__CMOC__) && !defined(__WINCMOC__)
    #include <cmoc.h>
#else
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
#endif

#if !defined EXIT_SUCCESS
    #define EXIT_SUCCESS 0
#endif

// TODO: REMOVE THIS
//#define DEBUG_ITEMS
//#define DEBUG_END


#include "settings.h"

#include "character.h"
#include "item.h"
#include "strategy.h"
#include "game_text.h"
#include "level.h"
#include "ghost.h"
#include "move_player.h"

#include "text_strings.h"

#include "init_images.h"

#include "display_macros.h"

#include "speed_game_settings.h"

#include "sleep_macros.h"

#if !defined(TINY_GAME)
    #include "bullet.h"
    #include "skull.h"
#endif
    
#include "end_screen.h"

#if defined(FULL_GAME)
    #include "horizontal_missile.h"
    #include "rocket.h"
#endif

#include "variables.h"

// uint16_t ghostSlowDown;

// #if !defined(TINY_GAME)
    // uint16_t ghostLevel;
// #endif

// uint16_t points;
// uint16_t highScore;
// uint8_t lives;

uint8_t skullsCount;

uint8_t bulletStrength;

// #if !defined(TINY_GAME) || defined(TURN_BASED)
// uint16_t loop;
// #endif
// uint8_t level;

uint8_t bombCount;

// #if !defined(TINY_GAME)
    // uint16_t skullSlowDown;
    // uint8_t skullXCountDown;
    // uint8_t skullYCountDown;
    // uint8_t bulletDirection[BULLETS_NUMBER];
// #endif

// Level
// The level affects:
// 1. powerUpCoolDown (how long before a new powerUp is spawned)
// 2. ghostSlowDown (how much the power up slows the enemies down)
// 3. skullXCountDown (time needed to activate the skull ghost)
// 4. skullYCountDown
// 5. skullSlowDown (how much the skull ghost is slowed-down)
// 6. skullLoopTrigger (how long before the skull ghost appears)

// #if !defined(TINY_GAME)
    // extern Image SKULL_IMAGE;
    // extern Image POWERUP_IMAGE;
    // extern Image BULLET_IMAGE;
    // extern Image GUN_IMAGE;
    // extern Image EXTRA_POINTS_IMAGE;    
    // extern Image DEAD_GHOST_IMAGE;
// #endif


// #if defined(FULL_GAME) && !defined(NO_BLINKING)
    // uint8_t playerBlink;    
// #endif

// Character player; 

// Character *chasedEnemyPtr;

#if !defined(TINY_GAME)
    // Item powerUp;
    // Item powerUp2;
    // Item gun;
    // Item extraPoints;    
    
    Character bullets[BULLETS_NUMBER];
#endif

Character skulls[SKULLS_NUMBER];

// Ghost ghosts[GHOSTS_NUMBER];
// Character bombs[BOMBS_NUMBER];

#if defined(FULL_GAME)

    // uint8_t innerVerticalWallY; 
    // uint8_t innerVerticalWallX; 
    // uint8_t innerVerticalWallLength;

    uint8_t innerHorizontalWallY; 
    uint8_t innerHorizontalWallX; 
    uint8_t innerHorizontalWallLength;

    // Item freeze;
    // Item invincibility;
    
    // Item extraLife;
    // Item super;
    // Item confuse;
    // Item zombie;
     
    // uint8_t extraLife_present_on_level;
    // uint8_t super_present_on_level;
    // uint8_t zombie_present_on_level;
    // #define confuse_present_on_level_condition missileBasesDestroyed

    // Character leftHorizontalMissile;
    // Character rightHorizontalMissile;

    // Character rockets[ROCKETS_NUMBER];

    // uint8_t rockets_x[ROCKETS_NUMBER];
    
    // uint8_t dead_rockets;
    
    // uint8_t arrowRange;
    
    // uint8_t skullsKilled;
    
    // uint8_t missileBasesDestroyed;
        
    // uint8_t invincibilityActive;
    
    // uint8_t confuseActive; 
    
    // uint8_t zombieActive; 
        
    // uint16_t invincibility_count_down;    
    
    // uint16_t confuse_count_down;
    
    // uint16_t zombie_count_down;
    
    uint8_t ghostsOnScreen;
    
#endif

// #if !defined(TINY_GAME)
    // uint8_t strategyArray[GHOSTS_NUMBER];

    // uint8_t playerDirection; // 0: right, 1: down, 2: left, 3: up
    
    // uint8_t freezeActive; // freezeActive    

    // uint16_t freeze_count_down;
        
    // uint16_t extraLifeThroughPointsCounter;    
// #endif

// uint8_t ghostCount; // = GHOSTS_NUMBER;

// #if !defined(TINY_GAME)
    // uint8_t playerFire;
    // uint8_t guns; // = GUNS_NUMBER;

    // uint8_t skullActive;
// #endif


#if !defined(TINY_GAME)
    void resetItems()
    {
        gun._coolDown = GUN_COOL_DOWN;
        powerUp._coolDown = POWER_UP_COOL_DOWN;
        powerUp2._coolDown = POWER_UP2_COOL_DOWN;
        extraPoints._coolDown = EXTRA_POINTS_COOL_DOWN;        
        
        #if defined(FULL_GAME)
            freeze._coolDown = FREEZE_COOL_DOWN;                
            invincibility._coolDown = INVINCIBILITY_COOL_DOWN;

            super._coolDown = SUPER_COOL_DOWN;
            extraLife._coolDown = EXTRA_LIFE_COOL_DOWN;
            
            confuse._coolDown = CONFUSE_COOL_DOWN;
            zombie._coolDown = ZOMBIE_COOL_DOWN;                
        #endif
    }

    
    // Constructor for all items
    void constructItems()
    {
        powerUp._effect = &powerUpEffect;
        powerUp2._effect = &powerUp2Effect;
        gun._effect = &gunEffect;
        extraPoints._effect = &extraPointsEffect;
        #if defined(FULL_GAME)
            freeze._effect = &freezeEffect;
            extraLife._effect = &extraLifeEffect;
            invincibility._effect = &invincibilityEffect;
            super._effect = &superEffect;
            confuse._effect = &confuseEffect;
            zombie._effect = &zombieEffect;
        #endif    
    }    

#endif

#if !defined(NO_INITIAL_SCREEN)            
void initialScreen(void)
{    
    CLEAR_SCREEN();                    
    printStartMessage();
    WAIT_PRESS();
    
    #if defined(FULL_GAME) && !defined(NO_HINTS)
        CLEAR_SCREEN();
        printHints();    
    #endif
}
#endif


#if defined(FULL_GAME)
    
    void handle_special_triggers(void)
    {
        // confuse_present_on_level_condition is defined as missileBasesDestroyed
        zombie_present_on_level = missileBasesDestroyed>=2;
        super_present_on_level = skullsKilled>=2;
        extraLife_present_on_level = super_present_on_level && confuse_present_on_level_condition;
    }
    
#endif

#if defined(SLOW_DOWN)
    #  if defined(__NCURSES__)
    
        void _slow_down(void)
        {
            usleep(SLOW_DOWN*1024);
        }
    #else
    void _slow_down(void)
    {
        short i;
        for(i=0;i<SLOW_DOWN;++i)
        {    
        }
    }
    #endif
#endif


int main(void)
{        
    INIT_GRAPHICS();

    INIT_INPUT();

    highScore = 0;
    
    while(1)
    {

        INIT_IMAGES();
        
        #if !defined(NO_SET_SCREEN_COLORS)
            // Set Screen Colors
            setScreenColors();                
        #endif
        
        #if !defined(NO_INITIAL_SCREEN)
            initialScreen();
            
            #if !defined(TINY_GAME)
                WAIT_PRESS();
                CLEAR_SCREEN();    
            #endif
        #else
            CLEAR_SCREEN();    
            
            printPressKeyToStart();                
        #endif

        #if !defined(LESS_TEXT) || defined(ALT_HIGHSCORE)
            highScoreScreen();
            WAIT_PRESS();    
        #endif

        #if !defined(TINY_GAME)

            CLEAR_SCREEN();
        #endif
        
        #if !defined(TINY_GAME)
            extraLifeThroughPointsCounter = 1;
        #endif
        points = 0;
        level = INITIAL_LEVEL;     
        lives = LIVES_NUMBER;
        
        ghostCount = GHOSTS_NUMBER + 4*level; 
         
        
        #if defined(FULL_GAME)
            #if defined(DEBUG_ITEMS)
                missileBasesDestroyed = 2;
                skullsKilled = 2;
            #else
                missileBasesDestroyed = 0;
                skullsKilled = 0;            
            #endif            
        #endif
        
        
        do // Level (Re-)Start
        {     
            #if defined(DEBUG_STRATEGY)
            ghostsOnScreen = 1;
            #else
            if(level<=2)
            {
                ghostsOnScreen = 5;
            }
            else if(level<=4)
            {
                ghostsOnScreen = 6;
            }
            else if (level<=8)
            {
                ghostsOnScreen = 7;
            }
            else
            {
                ghostsOnScreen = 8;
            }
            #endif
            
            skullsCount = SKULLS_NUMBER;
            
            bombCount = BOMBS_NUMBER;
            
            #if !defined(TINY_GAME) || defined(TURN_BASED)
            loop = 0;
            #endif
            
            #if !defined(TINY_GAME)
            ghostLevel = 0;
            #endif
        
            #if defined(FULL_GAME)
            
                dead_rockets = 0;
                
                invincibilityActive = 1;                
                invincibility_count_down = INITIAL_INVINCIBILITY_COUNT_DOWN;
                
                #if !defined(INITIAL_GHOST_FREEZE)
                    freezeActive = 0;
                #endif
                confuseActive = 0;
                zombieActive = 0; 
                
                handle_special_triggers();
                
                #if !defined(SIMPLE_STRATEGY)
                    computeStrategy();            
                #endif
                                
            #endif            
            
            #if !defined(TINY_GAME)
                skullActive = 0;
                guns = 0;
                
                resetItems();
                
                #if defined(INITIAL_GHOST_FREEZE)
                    freezeActive = 1;
                    freeze_count_down = INITIAL_FROZEN_COUNT_DOWN;
                #endif
                
                computeSkullParameters();                
            #endif

            #if defined(TINY_GAME)
                ghostSlowDown = INITIAL_GHOST_SLOWDOWN-(uint16_t)level*256;
            #else
                ghostSlowDown = computeGhostSlowDown();
            #endif
            
            CLEAR_SCREEN();
            #if !defined(LESS_TEXT)
                // Clear the screen, put cursor in upper left corner

                printLevel();
                SLEEP(1);
                CLEAR_SCREEN();
            #endif
                
            
            #if defined(FULL_GAME)
                        
                arrowRange = computeArrowRange();
            
                bulletStrength = 2;
            
                if(bossLevel())
                {
                    printKillTheSkull();
                    SLEEP(2);
                    ghostCount = level>>2;
                }
                CLEAR_SCREEN();
                
                updateInnerVerticalWall();    
                updateInnerHorizontalWall();                
            #endif
            
            printPressKeyToStart();
            WAIT_PRESS();
            CLEAR_SCREEN();
            
            
            #if !defined(TINY_GAME) && !defined(NO_BORDERS)
                DRAW_BORDERS();
            #endif
            
            fillLevelWithCharacters();            
            
            #if !defined(TINY_GAME)
                constructItems();    
                
                displayStatsTitles();
            #endif
            
            #if !defined(NO_STATS)
                displayStats();            
                printLevelStats();
                printLivesStats();
            #endif
            
            //
            #if !defined(TINY_GAME)
                printGunsStats();
                printGhostCountStats();
            #endif        
            
            while(player._status && (( ((ghostCount>0)&&(skullsCount)) && !bossLevel()) || (skullsCount && bossLevel()))) // while alive && there are still ghosts
            {                
                #if defined(DEBUG_END)
                    gameCompleted();
                #endif
                    
                #if !defined(TURN_BASED)
                    MOVE_PLAYER();                
                    _DRAW_PLAYER();    
                #endif
                
                #if defined(SLOW_DOWN)
                    _slow_down();
                #endif
                        
                #if defined(FULL_GAME)
                    handle_rockets();
                    handle_horizontal_missiles();
                #endif
                
                #if !defined(TINY_GAME) || defined(TURN_BASED)
                ++loop;
                #endif
                
                #if !defined(TINY_GAME)
                if(points>(extraLifeThroughPointsCounter*EXTRA_LIFE_THROUGH_POINTS))
                {
                    ++extraLifeThroughPointsCounter;
                    PING_SOUND();
                    ++lives;
                    printLivesStats();
                }
                #endif
                
                #if defined(TINY_GAME)
                    if(ghostSlowDown) 
                    {
                        --ghostSlowDown;
                    }
                #else
                    ghostSlowDown = computeGhostSlowDown();
                #endif
            
                #if !defined(TINY_GAME)
                    handle_bullets();
                #endif
                handle_bomb();
                
                #if !defined(TINY_GAME)                        

                    if(!freezeActive)
                    {
                        #if defined(FULL_GAME)
                            if(confuseActive && skullActive && skulls[0]._status)
                            {
                                chaseCharacter(&skulls[0], ghostSlowDown);
                            }
                            else
                            {
                                chaseCharacter(&player, ghostSlowDown);
                            }
                        #else
                            chaseCharacter(ghostSlowDown);
                        #endif
                        ++ghostLevel;            
                        
                    }
                
                    handle_skulls();

                    // This detects collisions of ghosts that have just moved
                    checkBullets();
                #else
                    #if !defined(NO_CHASE)
                        chaseCharacter(ghostSlowDown);
                        #if !defined(TINY_GAME)
                            ++ghostLevel;
                        #endif
                    #endif
                #endif
                
                // Check collisions bombs vs ghosts
                checkBombsVsGhosts();
                if(skullActive)
                {
                    checkBombsVsSkulls();
                }
                #if !defined(TINY_GAME)
                    handle_extraPoints_item();
                    handle_gun_item();
                    handle_powerup_item();
                    handle_powerup2_item();    
                    handle_freeze_count_down();                    
                #endif
                
                #if defined(FULL_GAME)
                    handle_freeze_item();    
                    handle_invincibility_item();
                    handle_invincibility_count_down();                    

                        
                    if(super_present_on_level)
                    {
                        handle_super_item();
                        if(extraLife_present_on_level)
                        {
                            handle_extraLife_item();
                        }
                    }
                    
                                        
                    if(confuse_present_on_level_condition)
                    {
                        handle_confuse_item();
                        handle_confuse_count_down();
                        if(zombie_present_on_level)
                        {
                            handle_zombie_item();
                            handle_zombie_count_down();    
                            if(zombieActive && !(loop&15))
                            {
                                points+=ZOMBIE_BONUS;
                                displayStats();
                                reducePowerUpsCoolDowns();
                            }
                        }
                    }
                    
                #endif
                
                #if defined(FULL_GAME)
                    if(wallReached(&player) || 
                       (!invincibilityActive && (playerReachedGhosts() || innerWallReached(&player) || innerHorizontalWallReached(&player)))
                      )
                #else
                    if(wallReached(&player) || playerReachedGhosts() )
                #endif
                    {
                        playerDies();
                    }
                
                // Display ghosts
                SKIP_GHOST_DRAW
                    displayGhosts();
                    
                #if defined(TURN_BASED) 
                    if((loop<TURN_BASED_MAX_LOOP) || loop&1)
                    {
                        MOVE_PLAYER();
                    }                    
                    _DRAW_PLAYER();    
                #endif
                
                #if defined(FULL_GAME)
                    
                    SKIP_WALL_DRAW
                    {
                        if(innerVerticalWallLevel())
                        {
                            DRAW_VERTICAL_LINE(XSize/2, YSize/2-(innerVerticalWallLength/2), innerVerticalWallLength);    
                        }
                        else if(innerHorizontalWallLevel())
                        {
                            DRAW_HORIZONTAL_LINE(XSize/2-(innerHorizontalWallLength/2), YSize/2, innerHorizontalWallLength);                                
                        }
                        displayBombs();                                                        
                    }
                                        
                #else
                    SKIP_BOMB_DRAW
                        displayBombs();
                #endif                
            }; // end inner while [while (player._alive && ghostCount>0), i.e., exit on death or end of level]

            _DRAW_PLAYER();
            if(player._status) // if level finished
            {
                #if defined(BETWEEN_LEVEL)
                    chasedEnemyPtr = &player;
                    SHOW_DOWN();
                #endif
                
                #if !defined(TINY_GAME)
                    #if !defined(LESS_TEXT)
                        SLEEP(1);
                        printVictoryMessage();
                        SLEEP(2);

                        CLEAR_SCREEN();
                    #endif

                    if(level<=10)
                    {
                        points+= LEVEL_BONUS*level;
                        printLevelBonus(LEVEL_BONUS*level);
                    }
                    else
                    {                
                        points+= LEVEL_BONUS*10;
                        printLevelBonus(LEVEL_BONUS*10);
                    }
                    SLEEP(1);
                    CLEAR_SCREEN();                        
                #else
                    points += LEVEL_BONUS * 4;
                #endif            

                ghostCount = GHOSTS_NUMBER + 4*level; 
                
                #if defined(FULL_GAME)            
                    if(bossLevel())
                    {    
                        CLEAR_SCREEN();
                        SLEEP(1);
                        PING_SOUND();
                        #if !defined(LESS_TEXT)
                            printExtraLife();
                        #endif
                        SLEEP(2);
                        ++lives;
                        skullsKilled = 1;
                        missileBasesDestroyed/=2;
                    }
                    else
                    {
                        if(!skullsCount)
                        {
                            ++skullsKilled;
                        }
                        missileBasesDestroyed+=dead_rockets;
                    }
                #endif
                ++level;

            }
            else // if dead
            {        
                #if defined(BETWEEN_LEVEL)
                    chasedEnemyPtr = &skulls[0];    
                #endif
                
                #if !defined(TINY_GAME)
                    CLEAR_SCREEN();
                #endif
                --lives;
                if(lives>0)
                {
                    player._status = 1;
                }
            }
            #if defined(BETWEEN_LEVEL)
                spiral(chasedEnemyPtr, 2*MIN_SIZE-18);
                SLEEP(1);
            #endif                
        } while (player._status && (level<(FINAL_LEVEL+1))); // lives left and not completed game game 
            
        if(level==FINAL_LEVEL+1) // if completed game
        {
            gameCompleted();
            #if !defined(NO_SLEEP)
                SLEEP(1);
            #else
                WAIT_PRESS();
            #endif
        }

        // GAME OVER    
        CLEAR_SCREEN();
        printGameOver();
        
        #if !defined(NO_SLEEP)
            SLEEP(1);
        #else
            WAIT_PRESS();
        #endif
        
        #if !defined(TINY_GAME) && !defined(LESS_TEXT)
            CLEAR_SCREEN();
            finalScore();
        
            #if !defined(NO_SLEEP)
                SLEEP(1);
            #else
                WAIT_PRESS();
            #endif
        
        #endif
        if(points>highScore)
        {
            highScore = points;
        }
        
    } // while(1) -> restart from the beginning

    return EXIT_SUCCESS;
}