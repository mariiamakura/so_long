#include "../include/so_long.h"

void check_status(const t_game *game)
{
    int32_t x = (int32_t) game->player->position.x * CELL_SIZE;
    int32_t y = (int32_t) game->player->position.y * CELL_SIZE;

    int index = 0;
    while (index < game->img->enemy->count) {
        mlx_instance_t enemy_instance = game->img->enemy->instances[index];
        if (x == enemy_instance.x && y == enemy_instance.y) {
            mlx_close_window(game->mlx);
            write(1, "You were eaten :(\n", 19);
        }
        index++;
    }
}

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
    check_status(game);
    while (count < game->img->enemy->count)
    {
        move_enemy(game, count);
        count++;
    }
}