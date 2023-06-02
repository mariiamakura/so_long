#include "../include/so_long.h"

void check_status(const t_game *game)
{
    int count;

    count = 0;
    while (count < game->img->enemy->count)
    {
        if (game->player_x * PIXELS == (size_t)game->img->enemy->instances[count].x
        && game->player_y * PIXELS == (size_t)game->img->enemy->instances[count].y)
        {
            sleep(1);
            mlx_close_window(game->mlx);
            write(1, "You were eaten :(\n", 19);
        }
        count++;
    }
}

void move_enemy(const t_game *game, int count)
{
    t_var   var;

    var.x = &game->img->enemy->instances[count].x;
    var.y = &game->img->enemy->instances[count].y;
    var.run_x = (rand() % 3 - 1) * 64;
    var.run_y = (rand() % 3 - 1) * 64;
    var.index_x = *var.x + var.run_x;
    var.index_y = *var.y + var.run_y;
    if (var.index_x != 0)
        var.index_x /= PIXELS;
    if (var.index_y != 0)
        var.index_y /= PIXELS;
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
    static int  i;

    count = 0;
    check_status(game);
    if (i++ < ELOOP)
        return ;
    while (count < game->img->enemy->count)
    {
        move_enemy(game, count);
        count++;
    }
    i = 0;
}