#include <stdlib.h>
#include <stack>
#include <array>
#include "consonants.hpp"

void addApple(int grid[grid_size][grid_size], bool updated[grid_size][grid_size])
{
    int aX, aY;
    do {
        aX = 1 + (rand() % (grid_size-2));
        aY = 1 + (rand() % (grid_size-2));
    } while (grid[aX][aY] != empty_tile);
    grid[aX][aY] = apple;
    updated[aX][aY] = apple;
}

bool updatePlayer(int grid[grid_size][grid_size], bool updated[grid_size][grid_size], int newPosX, int newPosY, int *body_len) {
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

bool movePlayer(direction input ,int grid[grid_size][grid_size], bool updated[grid_size][grid_size], int *posX, int *posY, int *body_len) {
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
/*
int main() {
    int grid[grid_size][grid_size] = {{0}};
    bool updated[grid_size][grid_size] = {{false}};

    char input_char = 'w';
    int posX = (grid_size / 2), posY = posX;
    int body_len = 1;
    bool ended = movePlayer(input_char, grid, updated, &posX, &posY, &body_len);
}*/
