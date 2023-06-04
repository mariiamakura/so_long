#include "../include/so_long.h"

u_int16_t row_count(char **map_as_arr)
{
    int i;

    i = 0;
    while (map_as_arr[i])
        i++;
    return (i);
}

u_int16_t count_coins(t_game *game)
{
    u_int16_t coins;
    u_int16_t x;
    u_int16_t y;

    coins = 0;
    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->grid[y][x] == 'C')
                coins++;
            x++;
        }
        y++;
    }
    return (coins);
}

t_point coordinates(char item, t_game *game) {
    int32_t y;
    int32_t x;
    int32_t height = game->height;
    int32_t width = game->width;

    y = 0;
    while (y < height) {
        x = 0;
        while (x < width) {
            if (game->grid[y][x] == item) {
                return (t_point) {x, y};
            }
            x++;
        }
        y++;
    }
    return (t_point) {0, 0};
}