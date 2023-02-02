#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#include "controler.hpp"
#include "display.hpp"

void appleHasSpace()
{
    int grid[grid_size][grid_size] = {0};
    bool updated[grid_size][grid_size] = {0};

    if (!addApple(grid,updated)) {
        printf("apple failed to be added.\n");
    }

    bool appleAdded = false;
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (grid[i][j] == apple && updated[i][j]) {
                appleAdded = true;
            } else if (grid[i][j] == apple ^ updated[i][j]) {
                printf("apple added error caused by diffrance.\n");
            }
        }
    }
    if (!appleAdded) {
        printf("apple added error caused.\n");
    }
}


void appleNoSpace()
{
    int grid[grid_size][grid_size] = {0};
    bool updated[grid_size][grid_size] = {0};
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            grid[i][j] = snake_body_min;
            updated[i][j] = false;
        }
    }

    if (addApple(grid,updated)) {
        printf("add apple should return false.\n");
    }

    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (grid[i][j] != snake_body_min || updated[i][j]) {
                printf("tiles should not be updated from no apple. for %d, %d", i, j);
            }
        }
    }
}

void movePlayerDownHitWall()
{
    int grid[grid_size][grid_size] = {0};
    bool updated[grid_size][grid_size] = {0};
    int posX = 0;
    int posY = grid_size - 1;
    int body_len = 2;
    if (!movePlayer(down,grid,updated,&posX,&posY,&body_len)) {
        printf("movePlayerDownHitWall failed to return false");
    }
}

void movePlayerUpHitWall()
{
    int grid[grid_size][grid_size] = {0};
    bool updated[grid_size][grid_size] = {0};
    int posX = 0;
    int posY = 0;
    int body_len = 2;
    if (!movePlayer(up,grid,updated,&posX,&posY,&body_len)) {
        printf("movePlayerUpHitWall failed to return false");
    }
}

void movePlayerLeftHitWall()
{
    int grid[grid_size][grid_size] = {0};
    bool updated[grid_size][grid_size] = {0};
    int posX = 0;
    int posY = 0;
    int body_len = 2;
    if (!movePlayer(left,grid,updated,&posX,&posY,&body_len)) {
        printf("movePlayerLeftHitWall failed to return false");
    }
}


void movePlayerRightHitWall()
{
    int grid[grid_size][grid_size] = {0};
    bool updated[grid_size][grid_size] = {0};
    int posX = grid_size - 1;
    int posY = 0;
    int body_len = 2;
    if (!movePlayer(right,grid,updated,&posX,&posY,&body_len)) {
        printf("movePlayerRightHitWall failed to return false");
    }
}


void movePlayerDownNotWall()
{
    int grid[grid_size][grid_size] = {snake_body_min,snake_body_min+1,snake_body_min+2};
    bool updated[grid_size][grid_size] = {0};
    int posX = 2;
    int posY = 2;
    int body_len = 2;
    if (movePlayer(down,grid,updated,&posX,&posY,&body_len)) {
        printf("movePlayerDownHitWall failed to return true.\n");
    }

    if (grid[0][0] != empty_tile) {
        printf("is not an empity tile.\n");
    }
    if (grid[0][1] != snake_body_min) {
        printf("is not an snake tile.\n");
    }
    if (grid[0][2] != snake_body_min+1) {
        printf("is not an snake tile.\n");
    }

    if (posX != 2 || posY != 3) {
        printf("down pos is the wrong value.\n");
    }

    if (grid[posX][posY] != snake_body_min+body_len-1) {
        printf("did not add the snake value.\n");
    }
}

void movePlayerUpNotWall()
{
    int grid[grid_size][grid_size] = {snake_body_min,snake_body_min+1,snake_body_min+2};
    bool updated[grid_size][grid_size] = {0};
    int posX = 2;
    int posY = 2;
    int body_len = 2;
    if (movePlayer(up,grid,updated,&posX,&posY,&body_len)) {
        printf("movePlayerDownHitWall failed to return true.\n");
    }

    if (grid[0][0] != empty_tile) {
        printf("is not an empity tile.\n");
    }
    if (grid[0][1] != snake_body_min) {
        printf("is not an snake tile.\n");
    }
    if (grid[0][2] != snake_body_min+1) {
        printf("is not an snake tile.\n");
    }

    if (posX != 2 || posY != 1) {
        printf("up pos is the wrong value.\n");
    }

    if (grid[posX][posY] != snake_body_min+body_len-1) {
        printf("did not add the snake value.\n");
    }
}

void movePlayerLeftNotWall()
{
    int grid[grid_size][grid_size] = {snake_body_min,snake_body_min+1,snake_body_min+2};
    bool updated[grid_size][grid_size] = {0};
    int posX = 2;
    int posY = 2;
    int body_len = 2;
    if (movePlayer(left,grid,updated,&posX,&posY,&body_len)) {
        printf("movePlayerDownHitWall failed to return true.\n");
    }

    if (grid[0][0] != empty_tile) {
        printf("is not an empity tile.\n");
    }
    if (grid[0][1] != snake_body_min) {
        printf("is not an snake tile.\n");
    }
    if (grid[0][2] != snake_body_min+1) {
        printf("is not an snake tile.\n");
    }

    if (posX != 1 || posY != 2) {
        printf("left pos is the wrong value.\n");
    }

    if (grid[posX][posY] != snake_body_min+body_len-1) {
        printf("did not add the snake value.\n");
    }
}

void movePlayerRightNotWall()
{
    int grid[grid_size][grid_size] = {snake_body_min,snake_body_min+1,snake_body_min+2};
    bool updated[grid_size][grid_size] = {0};
    int posX = 2;
    int posY = 2;
    int body_len = 2;
    if (movePlayer(right,grid,updated,&posX,&posY,&body_len)) {
        printf("movePlayerDownHitWall failed to return true.\n");
    }

    if (grid[0][0] != empty_tile) {
        printf("is not an empity tile.\n");
    }
    if (grid[0][1] != snake_body_min) {
        printf("is not an snake tile.\n");
    }
    if (grid[0][2] != snake_body_min+1) {
        printf("is not an snake tile.\n");
    }

    if (posX != 3 || posY != 2) {
        printf("rightpos is the wrong value.\n");
    }

    if (grid[posX][posY] != snake_body_min+body_len-1) {
        printf("did not add the snake value.\n");
    }
}



int main()
{
    appleHasSpace();
    appleNoSpace();

    movePlayerUpHitWall();
    movePlayerDownHitWall();
    movePlayerLeftHitWall();
    movePlayerRightHitWall();

    movePlayerDownNotWall();
    movePlayerUpNotWall();
    movePlayerLeftNotWall();
    movePlayerRightNotWall();

    printf("\ntests run.\n");
}
