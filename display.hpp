#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED
#define TEXT_SIZE 130

void openWindow();
void updateGridDisplay(int grid[grid_size][grid_size], bool updated[grid_size][grid_size]);
void exitWindow();

void viewScore(int score);
void viewGame(int grid[grid_size][grid_size], bool updated[grid_size][grid_size]);
#include "display.cpp"
#endif // DISPLAY_HPP_INCLUDED
