/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_with_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:15:55 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/08 18:16:51 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	choose_images(t_game *game, u_int16_t y, u_int16_t x)
{
	if (game->grid[y][x] == '1')
		if (mlx_image_to_window(game->mlx, game->img->bush,
				x * CELL_SIZE, y * CELL_SIZE) < 0)
			error_msg("Failed to put bushes to window");
	if (game->grid[y][x] == 'C')
		if (mlx_image_to_window(game->mlx, game->img->coins,
				x * CELL_SIZE, y * CELL_SIZE) < 0)
			error_msg("Failed to put sushi to window");
	if (game->grid[y][x] == 'P')
		if (mlx_image_to_window(game->mlx, game->img->player,
				x * CELL_SIZE, y * CELL_SIZE) < 0)
			error_msg("Failed to put player to window");
	if (game->grid[y][x] == 'E')
		if (mlx_image_to_window(game->mlx, game->img->exit_closed,
				x * CELL_SIZE, y * CELL_SIZE) < 0)
			error_msg("Failed to put closed exit to window");
	if (game->grid[y][x] == 'X')
		if (mlx_image_to_window(game->mlx, game->img->enemy,
				x * CELL_SIZE, y * CELL_SIZE) < 0)
			error_msg("Failed to put enemies to window");
}

void	fill_background(t_game *game)
{
	u_int16_t	x;
	u_int16_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (mlx_image_to_window(game->mlx, game->img->floor,
					x * CELL_SIZE, y * CELL_SIZE) < 0)
				error_msg("Failed to put image to window");
			x++;
		}
		y++;
	}
}

void	put_images(t_game *game)
{
	u_int16_t	y;
	u_int16_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			choose_images(game, y, x);
			x++;
		}
		y++;
	}
}
