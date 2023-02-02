#ifndef CONSONANTS_HPP_INCLUDED
#define CONSONANTS_HPP_INCLUDED
#define grid_size 50
#define max_window 685
#define cell_display_size grid_size
#define grid_sqear_size (max_window/grid_size)
#define max_x (grid_sqear_size*cell_display_size)
#define max_y (grid_sqear_size*cell_display_size)
#define empty_tile 0
#define apple -1
#define snake_body_min 2
#define nanosecs_to_sleep_mult 300000000
#define nanosecs_to_sleep_base 0.025
#define start_size 3
#define BACKGROUND_COLOR 0
#define APPLE_COLOR 12
#define SNAKE_COLOR 10

#define tile_border_size 0
//#define has_grid_lines

#ifdef has_grid_lines
#if tile_border_size < 1
#error invalid border size
#endif // tile_border_size
#endif // has_grid_lines

typedef enum {
    up,
    down,
    left,
    right
} direction;

#endif // CONSONANTS_HPP_INCLUDED
