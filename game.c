#include "common.h"

byte CellBoard[BOARD_WIDTH * BOARD_HEIGHT * 3];

byte BufferBoard[BOARD_WIDTH * BOARD_HEIGHT * 3];

int mod(int a, int b)
{
    return a - (a/b) * b;
}

int _I(int i, int j)
{
    return (i*BOARD_WIDTH+j)*3;
}

int get(byte* b, int i, int j)
{
    return (b[_I(i,j)] << 16) + (b[_I(i,j) + 1] << 8) + b[_I(i,j) + 2];
}

void set(byte* b, int i, int j, int value)
{
    b[_I(i,j)] = (unsigned char) ((value & 0x00FF0000) >> 16);
    b[_I(i,j)+1] = (unsigned char) ((value & 0x0000FF00) >> 8);
    b[_I(i,j)+2] = (unsigned char) (value & 0x000000FF);
}

void seed_board()
{
    for (int i = 0; i < BOARD_HEIGHT; i++) 
    {
        for (int j = 0; j < BOARD_WIDTH; j++) 
        {
            set(CellBoard, i, j, (rand() % 2) == 0 ? ALIVE : DEAD);
        }
    }
}

int count_neighbors(int x, int y)
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

            count += get(CellBoard, mod(i,BOARD_HEIGHT), mod(j,BOARD_WIDTH)) == ALIVE ? 1 : 0;
        }
    }

    return count;
}

void GameInit()
{
    seed_board();
}

void GameUpdate()
{    
    for (int i = 0; i < BOARD_HEIGHT; i++) 
    {
        for (int j = 0; j < BOARD_WIDTH; j++) 
        {
            int c = count_neighbors(i, j);

            if (get(CellBoard, i, j) == ALIVE)
                set(BufferBoard, i, j, (c == 3 || c == 2) ? ALIVE : DEAD);
            else 
                set(BufferBoard, i, j, (c == 3) ? ALIVE : DEAD);
        }
    }

    for (int i = 0; i < BOARD_HEIGHT; i++) 
    {
        for (int j = 0; j < BOARD_WIDTH; j++) 
        {
            set(CellBoard, i, j, get(BufferBoard, i, j));
        }
    }
}
