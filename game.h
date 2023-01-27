#ifndef __GAME__
#define __GAME__ "game.h"

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define WIDTH 1920
#define HEIGHT 1080

#define FULLSCREEN 1

#define ALIVE 0x00000000
#define DEAD 0x00FFFFFF

unsigned char* init_board(int,int);

void seed_board(unsigned char*,int,int);

void clear_board(unsigned char*,int,int);

void update_b(unsigned char*,int,int);

#endif /* ! */
