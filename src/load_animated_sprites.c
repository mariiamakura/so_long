#include "../include/so_long.h"

t_img *load_exit_closed_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t *exit;

    exit = mlx_load_png("./sprites/exit_closed.png");
    if (!exit)
        error_msg("Exit closed sprite couldn't be loaded");
    img->exit_closed = mlx_texture_to_image(mlx, exit);
    if (!img->exit_closed)
        error_msg("Problem with closed exit texture to image");
    mlx_delete_texture(exit);
    return (img);
}

t_img *load_exit_opened_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t *exit;

    exit = mlx_load_png("./sprites/exit_opened.png");
    if (!exit)
        error_msg("Exit opened sprite couldn't be loaded");
    img->exit_opened = mlx_texture_to_image(mlx, exit);
    if (!img->exit_opened)
        error_msg("Problem with opened exit texture to image");
    mlx_delete_texture(exit);
    return (img);
}

void load_animated_player(t_game *game)
{
    game->player_up = mlx_load_png("./sprites/samurai_back.png");
    if (!game->player_up)
        error_msg("Failed to load player_up image");
    game->player_down = mlx_load_png("./sprites/samurai_front.png");
    if (!game->player_down)
        error_msg("Failed to load player_down image");
    game->player_right = mlx_load_png("./sprites/samurai_right.png");
    if (!game->player_right)
        error_msg("Failed to load player_right image");
    game->player_left = mlx_load_png("./sprites/samurai_left.png");
    if (!game->player_left)
        error_msg("Failed to load player_left image");
}