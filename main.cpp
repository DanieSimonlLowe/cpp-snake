#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#include "controler.hpp"
#include "display.hpp"

direction u;

void inputKey(char key, direction *i)
{
    switch (key) {
    case 72:
        if (u != down) {
            *i = up;
        }
        break;
    case 80:
        if (u != up) {
            *i = down;
        }
        break;
    case 75:
        if (u != right) {
            *i = left;
        }
        break;
    case 77:
        if (*i != left) {
            *i = right;
        }
    default:
        break;
    }
}


DWORD WINAPI inputThread(void *input)
{
    direction *i = (direction *)input;
    char c;
    while (true) {
        c = getch();
        switch(c) {
        case '8':
        case 'w':
            if (u != down) {
                *i = up;
            }
            break;
        case '4':
        case 'a':
            if (u != right) {
                *i = left;
            }
            break;
        case '2':
        case 's':
            if (u != up) {
                *i = down;
            }
        break;
        case '6':
        case 'd':
            if (u != left) {
                *i = right;
            }
            break;
        case 0:
            inputKey(getch(), i);
        default:
            break;
        }
    }
}

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

    direction input = down;
    u = input;
    int posX = (grid_size / 2);
    int posY = (grid_size/2);
    int body_len = start_size;

    bool ended = false;


    getch();

    /* creates thread for inputing direction.*/
    thread = CreateThread(NULL, 0, inputThread, (void*) &input, 0, NULL);
    struct timespec remaining, request;
    float len_factor;
    int old_len = -1;
    while(!ended) {
        u = input;
        ended = movePlayer(u, grid, updated, &posX, &posY, &body_len);
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
