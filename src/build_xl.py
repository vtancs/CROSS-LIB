#!/bin/python

import shutil

import os,sys


if len(sys.argv)<2:
    game_dir = "helloworld"
else:
    game_dir = sys.argv[1]

if(game_dir in ["tiles","sounds","matrix","invaders","zombies"]):
    project_type = "demo"
else:
    project_type = "game" 

parent_dir = project_type + "s"

if len(sys.argv)<3:
    target = "ncurses"
else:
    target = sys.argv[2]

if len(sys.argv)<4:
    compile_mode = "parallel"
else:
    if(sys.argv[3] != "parallel"):
        compile_mode = "sequential"
    else:
        compile_mode = "parallel"

if len(sys.argv)<5:
    optimization = "no"
else:
    optimization = "yes"

print("Project name: " + game_dir)
print("Project type: " + project_type)
print("Compile mode: " + compile_mode)
print("Optimization: " + optimization)

parent_and_game_dir = parent_dir + "/" + game_dir

if not os.path.exists(parent_and_game_dir):
    print("Game project not found!")
    exit();

make_command = "make " + target + " -f " + parent_dir+"/"+game_dir+"/Makefile."+game_dir;

print("run command : " + make_command)
print("\n")

os.system(make_command)