#include "input.hpp"




void inputKey(char key, direction *dir, direction oldDir)
{
    switch (key) {
    case 72:
        if (oldDir != down) {
            *dir = up;
        }
        break;
    case 80:
        if (oldDir != up) {
            *dir = down;
        }
        break;
    case 75:
        if (oldDir != right) {
            *dir = left;
        }
        break;
    case 77:
        if (oldDir != left) {
            *dir = right;
        }
    default:
        break;
    }
}


DWORD WINAPI inputThread(void *input)
{
    direction *dirs = (direction *)input;
    direction *dir = dirs;
    direction *dirOld = (dirs+1);


    char key;
    while (true) {
        key = getch();
        switch(key) {
        case '8':
        case 'w':
            if (*dirOld != down) {
                *dir = up;
            }
            break;
        case '4':
        case 'a':
            if (*dirOld != right) {
                *dir = left;
            }
            break;
        case '2':
        case 's':
            if (*dirOld != up) {
                *dir = down;
            }
        break;
        case '6':
        case 'd':
            if (*dirOld != left) {
                *dir = right;
            }
            break;
        case 0:
            inputKey(getch(), dir, *dirOld);
        default:
            break;
        }
    }

}


