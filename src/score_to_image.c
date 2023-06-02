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

void check_game_status(t_game *game)
{
    print_moves(game);
    if (game->collected == game->coins)
    {
        if (mlx_image_to_window(game->mlx, game->img->exit_opened,
                                game->exit_x * PIXELS, game->exit_y * PIXELS) < 0)
            error_msg("Failed to put opened exit to window");
        game->grid[game->exit_y][game->exit_x] = '0';
        if (game->player_x == game->exit_x && game->player_y == game->exit_y)
        {
            sleep(1);
            mlx_close_window(game->mlx);
            write(1, "Congratulations!\n", 18);
            write(1, "You ate all sushi!\n", 20);
        }
    }
}