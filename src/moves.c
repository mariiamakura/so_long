#include "../include/so_long.h"

void     player_animation(t_game *game, char direction)
{
    if (direction == 'u')
        mlx_draw_texture(game->img->player, game->player_up, 0, 0);
    if (direction == 'd')
        mlx_draw_texture(game->img->player, game->player_down, 0, 0);
    if (direction == 'r')
        mlx_draw_texture(game->img->player, game->player_right, 0, 0);
    if (direction == 'l')
        mlx_draw_texture(game->img->player, game->player_left, 0, 0);
}

void move_player(t_game *game, char coordinate, char direction)
{
    if (coordinate == 'y')
    {
        if (direction == 'u')
            move_up(game);
        else
            move_down(game);
    }
    if (coordinate == 'x')
    {
        if (direction == 'r')
            move_right(game);
        else
            move_left(game);
    }
}

void move_image(t_game *game, char coordinate, char direction)
{
    move_player(game, coordinate, direction);
    player_animation(game, direction);
}

void move_hook(mlx_key_data_t keydata, void *data)
{
    t_game *game;

    game = (t_game *)data;
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
        && keydata.action == MLX_PRESS)
        move_image(game, 'y', 'u');
    if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
        && keydata.action == MLX_PRESS)
        move_image(game, 'x', 'r');
    if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
        && keydata.action == MLX_PRESS)
        move_image(game, 'y', 'd');
    if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
        && keydata.action == MLX_PRESS)
        move_image(game, 'x', 'l');
}




