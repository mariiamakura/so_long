#include "../include/so_long.h"

t_img *load_floor_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t *floor;

    floor = mlx_load_png("./sprites/floor.png");
    if (!floor)
        error_msg("Floor sprite couldn't be loaded");
    img->floor = mlx_texture_to_image(mlx, floor);
    if (!img->floor)
        error_msg("Problem with floor texture to image");
    mlx_delete_texture(floor);
    return (img);
}

t_img *load_bush_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t *bush;

    bush = mlx_load_png("./sprites/bush.png");
    if (!bush)
        error_msg("Bush sprite couldn't be loaded");
    img->bush = mlx_texture_to_image(mlx, bush);
    if (!img->bush)
        error_msg("Problem with bush texture to image");
    mlx_delete_texture(bush);
    return (img);
}

t_img *load_coins_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t *coins;

    coins = mlx_load_png("./sprites/sushi.png");
    if (!coins)
        error_msg("Sushi sprite couldn't be loaded");
    img->coins = mlx_texture_to_image(mlx, coins);
    if (!img->coins)
        error_msg("Problem with sushi texture to image");
    mlx_delete_texture(coins);
    return (img);
}

t_img *load_player_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t *player;

    player = mlx_load_png("./sprites/samurai_front.png");
    if (!player)
        error_msg("Player sprite couldn't be loaded");
    img->player = mlx_texture_to_image(mlx, player);
    if (!img->player)
        error_msg("Problem with player texture to image");
    mlx_delete_texture(player);
    return (img);
}

t_img *load_enemy_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t *enemy;

    enemy = mlx_load_png("./sprites/enemy.png");
    if (!enemy)
        error_msg("Enemy sprite couldn't be loaded");
    img->enemy = mlx_texture_to_image(mlx, enemy);
    if (!img->enemy)
        error_msg("Problem with enemy texture to image");
    mlx_delete_texture(enemy);
    return (img);
}



