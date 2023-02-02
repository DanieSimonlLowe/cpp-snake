#ifndef CONTROLER_HPP_INCLUDED
#define CONTROLER_HPP_INCLUDED
#include "consonants.hpp"
#include "controler.cpp"
bool movePlayer(direction input ,int grid[grid_size][grid_size], bool updated[grid_size][grid_size], int *posX, int *posY, int *body_len);
bool addApple(int grid[grid_size][grid_size], bool updated[grid_size][grid_size]);
#endif // CONTROLER_HPP_INCLUDED
