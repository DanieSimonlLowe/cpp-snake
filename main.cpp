#include "controler.hpp"
#include "display.hpp"
#include "input.h"
#include <time.h>

float get_clock_factor(int body_len)
{
    return nanosecs_to_sleep_base + 1 / (log2(body_len)+1);
}


int main()
{
    HANDLE thread = NULL;
    openWindow();
    srand(time(0));
    int grid[grid_size][grid_size] = {{0}};
    bool updated[grid_size][grid_size] = {{false}};
    addApple(grid,updated);

    direction input[2] = {down, up};

    int posX = (grid_size / 2);
    int posY = (grid_size / 2);
    int body_len = start_size;

    bool ended = false;


    getch();

    /* creates thread for inputing direction.*/
    thread = CreateThread(NULL, 0, inputThread, (void*) input, 0, NULL);
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
    exitWindow();
}
