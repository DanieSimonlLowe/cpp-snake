#include "controler.hpp"
#include "display.hpp"
#include "input.hpp"
#include <time.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>

float get_clock_factor(int body_len)
{
    return nanosecs_to_sleep_base + 1 / (log2(body_len)+1);
}

void resetGrid(int grid[grid_size][grid_size], bool updated[grid_size][grid_size]) {
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (grid[i][j] != empty_tile) {
                updated[i][j] = true;
                grid[i][j] = empty_tile;
            }
        }
    }
}

int main()
{
    // set up background
    HANDLE thread = NULL;
    openWindow();
    srand(time(0));
    direction input[2] = {down, down};
    thread = CreateThread(NULL, 0, inputThread, (void*) input, 0, NULL);

    getch();
    int grid[grid_size][grid_size] = {{0}};
    bool updated[grid_size][grid_size] = {{false}};

    while (true) {
        //set up game values.
        addApple(grid,updated);

        int posX = (grid_size / 2);
        int posY = (grid_size / 2);
        int body_len = start_size;

        bool ended = false;

        struct timespec remaining, request;
        float len_factor;
        int old_len = -1;

        while(!ended) {
            ended = movePlayer(input[0], grid, updated, &posX, &posY, &body_len);
            input[1] = input[0];
            updateGridDisplay(grid, updated);
            if (old_len != body_len) {
                len_factor = get_clock_factor(body_len);
                old_len = body_len;
            }
            remaining, request = {0,  nanosecs_to_sleep_mult*len_factor};
            nanosleep(&request, &remaining);

        }

        viewScore(body_len - start_size);
        char key = getch();
        if (key == 'q') {
            exitWindow();
            return 0;
        }
        resetGrid(grid, updated);
        viewGame(grid, updated);
    }


}
