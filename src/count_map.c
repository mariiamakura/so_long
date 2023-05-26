#include "../include/so_long.h"

size_t row_count(char **map_as_arr)
{
    int i;

    i = 0;
    while (map_as_arr[i])
        i++;
    return (i);
}

size_t count_coins(t_game *game)
{
    size_t coins;
    size_t x;
    size_t y;

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

size_t coordinates(char item, t_game *game, char coordinate_c)
{
    size_t y;
    size_t x;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->grid[y][x] == item)
            {
                if (coordinate_c == 'y')
                    return (y);
                else
                    return (x);
            }
            x++;
        }
        y++;
    }
    return (0);
}