#include <graphics.h>
#include "consonants.hpp"

void openWindow()
{
    initwindow(max_x,max_y);
    #ifdef has_grid_lines
    setcolor(15);
    for (int i = 1; i < grid_size; i ++) {
        line(i*(*grid_x),0 ,i*(*gridx), max_y);
        line(0,i*(*grid_y) ,maxx, i*(*grid_y));
    }
    #endif
    return ;
}

void updateTileDisplay(int state , int i, int j) {
    switch(state) {
    case empty_tile:
        setfillstyle(1,BACKGROUND_COLOR); /* set black*/
        break;
    case apple:
        setfillstyle(1,APPLE_COLOR); /*set red*/
        break;
    default: //snake body
        setfillstyle(1,SNAKE_COLOR); /*set green*/
        break;
    }
    bar(grid_sqear_size*i+tile_border_size,grid_sqear_size*j+tile_border_size,grid_sqear_size*(i+1),grid_sqear_size*(j+1));

}


void updateGridDisplay(int grid[grid_size][grid_size], bool updated[grid_size][grid_size])
{
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (updated[i][j] == true) {
                updateTileDisplay(grid[i][j], i, j);
                updated[i][j] = false;
            }
        }
    }
}

void exitWindow() {
    closegraph();

}
