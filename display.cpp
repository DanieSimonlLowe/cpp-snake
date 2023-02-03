#include <graphics.h>
#include "consonants.hpp"
#include <math.h>

void openWindow()
{
    initwindow(max_x,max_y);
    #ifdef has_grid_lines
    setcolor(15);

    for (int i = 1; i < grid_size; i ++) {
        #if tile_border_size < 2
        line(i*(grid_sqear_size),0 ,i*(grid_sqear_size), max_y);
        line(0,i*(grid_sqear_size) ,max_x, i*(grid_sqear_size));
        #else
        bar(i*(grid_sqear_size),0 ,i*(grid_sqear_size)+tile_border_size, max_y);
        bar(0,i*(grid_sqear_size) ,max_x, i*(grid_sqear_size)+tile_border_size);
        #endif // tile_border_size
    }

    #endif
    return ;
}

void updateTileDisplay(int state , int i, int j)
{
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

void viewScore(int score)
{
    setactivepage(1);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    char str[15+5];
    sprintf(str, "your score is %d", score);
    outtextxy(max_x/2-TEXT_SIZE,max_y/2,str);
    setvisualpage(1);
}

void viewGame(int grid[grid_size][grid_size], bool updated[grid_size][grid_size])
{
    setactivepage(0);
    updateGridDisplay(grid, updated);
    setvisualpage(0);

}

void exitWindow()
{
    closegraph();

}
