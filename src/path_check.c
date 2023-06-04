#include "../include/so_long.h"

void free_game_struct_copy(char **grid, u_int16_t height)
{
    u_int16_t  i;

    i = 0;
    while (i < height)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}

int path_check_algo(t_game *temp, u_int16_t x, u_int16_t y) {
    if (temp->grid[y][x] == '1')
        return (0);
    if (temp->grid[y][x] == 'C')
        temp->coins--;
    if (temp->grid[y][x] == 'E') {
        temp->exit_position.x = 1;
        return (0);
    }
    temp->grid[y][x] = '1';
    if (path_check_algo(temp, x, y + 1))
        return (1);
    if (path_check_algo(temp, x, y - 1))
        return (1);
    if (path_check_algo(temp, x + 1, y))
        return (1);
    if (path_check_algo(temp, x - 1, y))
        return (1);
    return (0);
}

//creating copy of game struct so we wouldnt modify *game itself
void path_check_begin(t_game *game)
{
    t_game temp;
    u_int16_t i;

    i = 0;
    temp.height = game->height;
    temp.width = game->width;
    temp.coins = game->coins;
    temp.player = game->player;
    temp.exit_position.x = 0;
    temp.grid = (char **)malloc(temp.height * sizeof(char *));
    if (!temp.grid)
        error_msg("Grid allocation in temp struct failed");
    while (i < temp.height)
    {
        temp.grid[i] = ft_strdup(game->grid[i]);
        i++;
    }
    path_check_algo(&temp, temp.player->position.x, temp.player->position.y);
    if (!(temp.exit_position.x == 1 && temp.coins == 0))
        error_msg("No valid path is found");
    free_game_struct_copy(temp.grid, temp.height);
}