#include "game.h"

int mod(int a, int b)
{
    return a - (a/b) * b;
}

int _I(int i, int j, int w)
{
    return (i*w+j)*3;
}

GLint get(unsigned char* b, int i, int j, int w)
{
    return (b[_I(i,j,w)] << 16) + (b[_I(i,j,w) + 1] << 8) + b[_I(i,j,w) + 2];
}

void set(unsigned char* b, int i, int j, int value, int w)
{
    b[_I(i,j,w)] = (unsigned char) ((value & 0x00FF0000) >> 16);
    b[_I(i,j,w)+1] = (unsigned char) ((value & 0x0000FF00) >> 8);
    b[_I(i,j,w)+2] = (unsigned char) (value & 0x000000FF);
}

unsigned char* init_board(int w, int h)
{
    return malloc(sizeof(unsigned char)*w*h*3);
}

void clear_board(unsigned char* b, int h, int w)
{
    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++) 
        {
            set(b, i, j, DEAD, w);
        }
    }
}

void seed_board(unsigned char* b, int w, int h)
{
    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++) 
        {
            set(b, i, j, (rand() % 2) == 0 ? ALIVE : DEAD, w);
        }
    }
}

int count_neighbors(unsigned char* b, int x, int y, int w, int h)
{
    int count = 0;

    for (int i = x-1; i <= x+1; i++) 
    {
        for (int j = y-1; j <= y+1; j++) 
        {
            if (i == x && j == y)
            {
                continue;
            }

            count += get(b, mod(i,h), mod(j,w), w) == ALIVE ? 1 : 0;
        }
    }

    return count;
}

void update_b(unsigned char* b, int w, int h)
{
    unsigned char* nb = init_board(w, h);

    clear_board(nb, w, h);

    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++) 
        {
            int c = count_neighbors(b, i, j, w, h);

            if (get(b, i, j, w) == ALIVE)
                set(nb, i, j, (c == 3 || c == 2) ? ALIVE : DEAD, w);
            else 
                set(nb, i, j, (c == 3) ? ALIVE : DEAD, w);
        }
    }

    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++) 
        {
            set(b, i, j, get(nb, i, j, w), w);
        }
    }

    free(nb);
}
