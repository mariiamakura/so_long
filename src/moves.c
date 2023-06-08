/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:20:53 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/08 18:37:26 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	remove_coin(t_game *game, t_point position)
{
	int32_t			x;
	int32_t			y;
	mlx_instance_t	*instance;
	int				index;

	x = position.x * CELL_SIZE;
	y = position.y * CELL_SIZE;
	index = 0;
	while (index < game->img->coins->count)
	{
		instance = &game->img->coins->instances[index];
		if (instance->x == x && instance->y == y)
			instance->enabled = false;
		index++;
	}
	game->grid[position.y][position.x] = '0';
	game->collected += 1;
}

void	move_player(t_game *game, t_point position)
{
	int32_t	x;
	int32_t	y;

	x = position.x * CELL_SIZE;
	y = position.y * CELL_SIZE;
	game->player->position = position;
	game->img->player->instances[0].x = x;
	game->img->player->instances[0].y = y;
	game->steps += 1;
}

void	player_animation(t_game *game, t_point direction)
{
	if (direction.y < 0)
		mlx_draw_texture(game->img->player, game->img->player_up, 0, 0);
	else if (direction.y > 0)
		mlx_draw_texture(game->img->player, game->img->player_down, 0, 0);
	else if (direction.x > 0)
		mlx_draw_texture(game->img->player, game->img->player_right, 0, 0);
	else if (direction.x < 0)
		mlx_draw_texture(game->img->player, game->img->player_left, 0, 0);
}
