#include "../include/so_long.h"

void move_enemy(const t_game *game, int count)
{
    t_var   var;

    var.x = &game->img->enemy->instances[count].x;
    var.y = &game->img->enemy->instances[count].y;
    var.run_x = (rand() % 3 - 1) * CELL_SIZE;
    var.run_y = (rand() % 3 - 1) * CELL_SIZE;
    var.index_x = *var.x + var.run_x;
    var.index_y = *var.y + var.run_y;
    if (var.index_x != 0)
        var.index_x /= CELL_SIZE;
    if (var.index_y != 0)
        var.index_y /= CELL_SIZE;
    if (game->grid[var.index_y][var.index_x] != '1'
        && game->grid[var.index_y][var.index_x] != 'E')
    {
        *var.x += var.run_x;
        *var.y += var.run_y;
    }
}

void enemy_patrol(void *temp)
{
    const t_game    *game = temp;
    int count;

    count = 0;
    while (count < game->img->enemy->count)
    {
        move_enemy(game, count);
        count++;
    }
}