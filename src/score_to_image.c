#include "../include/so_long.h"

void score_to_image(t_game *game)
{
    game->img->moves_print = mlx_put_string(game->mlx, "MOVES:",
                                            16, game->height * 64 - 44);
    mlx_put_string(game->mlx, "SUSHI:", 160, game->height * 64 - 44);
}

void print_coins(t_game *game)
{
    char *str;

    str = ft_itoa(game->collected + 1);
    mlx_delete_image(game->mlx, game->img->coins_num);
    game->img->coins_num = mlx_put_string(game->mlx, str, 224,
                                          game->height * 64 - 44);
    free(str);
}

void print_moves(t_game *game)
{
    char *str;

    str = ft_itoa(game->steps);
    mlx_delete_image(game->mlx, game->img->moves_num);
    game->img->moves_num = mlx_put_string(game->mlx, str,
                                          80, game->height * 64 - 44);
    free(str);
}

void check_game_status(t_game *game) {
    t_point player_position = game->player->position;
    t_point exit_position = game->exit_position;
    int32_t x = exit_position.x * CELL_SIZE;
    int32_t y = exit_position.y * CELL_SIZE;

    print_moves(game);

    if (game->collected == game->coins) {
        if (mlx_image_to_window(game->mlx, game->img->exit_opened, x, y) < 0) {
            error_msg("Failed to put opened exit to window");
        }
        game->grid[exit_position.y][exit_position.x] = '0';
        if (player_position.x == exit_position.x && player_position.y == exit_position.y) {
            mlx_close_window(game->mlx);
            write(1, "Congratulations!\n", 18);
            write(1, "You ate all sushi!\n", 20);
        }
    }
}