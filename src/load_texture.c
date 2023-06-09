/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:33:07 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/08 18:13:08 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_floor_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./sprites/floor.png");
	if (floor == NULL)
		error_msg("Floor sprite couldn't be loaded");
	img->floor = mlx_texture_to_image(mlx, floor);
	if (img->floor == NULL)
		error_msg("Problem with floor texture to image");
	mlx_delete_texture(floor);
}

void	load_bush_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*bush;

	bush = mlx_load_png("./sprites/bush.png");
	if (bush == NULL)
		error_msg("Bush sprite couldn't be loaded");
	img->bush = mlx_texture_to_image(mlx, bush);
	if (img->bush == NULL)
		error_msg("Problem with bush texture to image");
	mlx_delete_texture(bush);
}

void	load_coins_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*coins;

	coins = mlx_load_png("./sprites/sushi.png");
	if (coins == NULL)
		error_msg("Sushi sprite couldn't be loaded");
	img->coins = mlx_texture_to_image(mlx, coins);
	if (img->coins == NULL)
		error_msg("Problem with sushi texture to image");
	mlx_delete_texture(coins);
}

void	load_player_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./sprites/samurai_front.png");
	if (player == NULL)
		error_msg("Player sprite couldn't be loaded");
	img->player = mlx_texture_to_image(mlx, player);
	if (img->player == NULL)
		error_msg("Problem with player texture to image");
	mlx_delete_texture(player);
	img->player_up = mlx_load_png("./sprites/samurai_back.png");
	if (img->player_up == NULL)
		error_msg("Failed to load player_up image");
	img->player_down = mlx_load_png("./sprites/samurai_front.png");
	if (img->player_down == NULL)
		error_msg("Failed to load player_down image");
	img->player_right = mlx_load_png("./sprites/samurai_right.png");
	if (img->player_right == NULL)
		error_msg("Failed to load player_right image");
	img->player_left = mlx_load_png("./sprites/samurai_left.png");
	if (img->player_left == NULL)
		error_msg("Failed to load player_left image");
}

void	load_enemy_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("./sprites/enemy.png");
	if (enemy == NULL)
		error_msg("Enemy sprite couldn't be loaded");
	img->enemy = mlx_texture_to_image(mlx, enemy);
	if (img->enemy == NULL)
		error_msg("Problem with enemy texture to image");
	mlx_delete_texture(enemy);
}
