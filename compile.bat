@REM set cc65path="C:\Retro\DEV\cc65-snapshot-win32"
@REM set mypath="C:\Users\Brizio\Documents\GitHub\PortableChase"
@REM set configpath="C:\Users\Brizio\Documents\GitHub\PortableChase\experiments"

@REM 
set cc65path="D:\personal\cc65-snapshot-win32"
@REM 
set configpath="D:\Userfiles\fcaruso\Documents\GitHub\ASCII-CHASE\experiments"
@REM 
set mypath="d:\Userfiles\fcaruso\Documents\GitHub\ASCII-CHASE"


set Deliverables=%mypath%\deliverables

mkdir %deliverables% 2> NUL

del %deliverables%\*
del %mypath%\atmos\*.o
del %mypath%\c64\*.o
del %mypath%\patch\*.o

cd %cc65path%\bin\

cl65.exe -O -t c64 %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\c64.prg

cl65.exe -O -t c64 --config %configpath%\cfg\c64_HACKED.cfg %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\c64_hack.prg


@REM cl65.exe -O -t c64 --config %configpath%\cfg\c64_HACKED.cfg  --module %configpath%\cfg\sprites.gfx  %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\c64_hack.prg

@REM cl65.exe -O -t c128 %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\c128.prg

@REM cl65.exe -O -t pet %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\cpet.prg

@REM cl65.exe -O -t vic20 --config %cc65path%\cfg\vic20-32k.cfg %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\cvic20-24k.prg


@REM cl65.exe -O -t plus4 %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\cplus4.prg

@REM cl65.exe -O -t c16 %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\c16-32k.prg

@REM cl65.exe -O -t cbm510 %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\cbm510.prg

@REM cl65.exe -O -t atari %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\atari800.xex

@REM Atmos has a conio issue (fixed with a patch)

@REM cl65.exe -O -t atmos %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\atmos.tap




@REM TARGETS MEMORY LIMITATIONS

@REM Atari 5200: Out of memory
@REM cl65.exe -O -t atari5200 %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\atari5200.a52

@REM Atari 2600: Out of memory
@REM cl65.exe -O -t atari2600 %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\atari2600.a26

@REM vic20-16k has reached its memory limitations
@REM cl65.exe -O -t vic20 --config %cc65path%\cfg\vic20-16k.cfg %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\cvic20-16k.prg

@REM pce runs out of memory
@REM cl65.exe -O -t pce %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\pcengine.bin



@REM TARGETS WITH OTHER ISSUES

@REM apple2 has a "sleep" issue
@REM cl65.exe -O -t apple2 %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\apple2.bin

@REM NES needs some INPUT
@REM cl65.exe -O -t nes %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\nes.nes



@REM BBC fails looking for bbc.lib
@REM cl65.exe -O -t bbc  %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\bbc.bin

