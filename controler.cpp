#include <stdlib.h>
#include <stack>
#include <array>
#include "consonants.hpp"

bool addApple(int grid[grid_size][grid_size], bool updated[grid_size][grid_size])
{
    int aX, aY, sX, sY;
    sX = 1 + (rand() % (grid_size-2));
    sY = 1 + (rand() % (grid_size-2));
    aX = sX;
    aY = sY;
    while (grid[aX][aY] != empty_tile) {
        aX++;
        if (aX >= grid_size) {
            aY++;
            aX = 0;
            if (aY >= grid_size) {
                aY = 0;
            }
        }


        if (aX == sX && aY == sY) {
            return false;
        }
    }
    grid[aX][aY] = apple;
    updated[aX][aY] = apple;
    return true;
}

bool updatePlayer(int grid[grid_size][grid_size], bool updated[grid_size][grid_size], int newPosX, int newPosY, int *body_len)
{
    if (newPosX < 0 || newPosY < 0) {
        return true;
    } else if (newPosX >= grid_size || newPosY >= grid_size) {
        return true;
    }
    if (grid[newPosX][newPosY] == apple) {
        (*body_len)++;
        addApple(grid, updated);
    } else if (grid[newPosX][newPosY] >= snake_body_min) {
        return true;
    }


    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (snake_body_min <= grid[i][j] ) {
                grid[i][j]--;
                if (grid[i][j] < snake_body_min) {
                    grid[i][j] = empty_tile;
                    updated[i][j] = true;
                }
            }
        }
    }
    updated[newPosX][newPosY] = true;
    grid[newPosX][newPosY] = *body_len + (snake_body_min - 1);
    return false;
}

bool movePlayer(direction input ,int grid[grid_size][grid_size], bool updated[grid_size][grid_size], int *posX, int *posY, int *body_len)
{
    switch(input) {
    case (up):
        (*posY)--;
        break;
    case (down):
        (*posY)++;
        break;
    case (left):
        (*posX)--;
        break;
    case (right):
        (*posX)++;
        break;
    }

    return updatePlayer(grid, updated, *posX, *posY, body_len);
}

