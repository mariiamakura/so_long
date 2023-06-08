/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:13:24 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/08 19:29:51 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mlx_loop_hook_callback(void *param)
{
	t_game			*game;
	static double	tick_elapsed_time = 0.0;

	game = (t_game *) param;
	tick_elapsed_time += game->mlx->delta_time;
	if (tick_elapsed_time > TICK_DELAY)
	{
		tick_elapsed_time -= TICK_DELAY;
		tick_callback(game);
	}
}

void	tick_callback(t_game *game)
{
	static int	player_elapsed_tick = 0;
	static int	enemy_elapsed_tick = 0;
	int			run_x;
	int			run_y;

	run_x = 0;
	run_y = 0;
	player_elapsed_tick++;
	enemy_elapsed_tick++;
	if (player_elapsed_tick > PLAYER_DELAY)
		player_elapsed_tick -= PLAYER_DELAY;
	if (enemy_elapsed_tick > ENEMY_DELAY)
	{
		enemy_elapsed_tick -= ENEMY_DELAY;
		enemy_patrol(game, run_x, run_y);
	}
	repaint_status_bar(game);
	check_game_status(game);
}

void	enemy_patrol(t_game *game, int run_x, int run_y)
{
	int				count;
	mlx_instance_t	*enemy;
	int				index_x;
	int				index_y;
	char			cell;

	count = 0;
	while (count < game->img->enemy->count)
	{
		enemy = &game->img->enemy->instances[count];
		run_x = rand() % 3 - 1;
		run_y = rand() % 3 - 1;
		index_x = enemy->x / CELL_SIZE + run_x;
		index_y = enemy->y / CELL_SIZE + run_y;
		cell = game->grid[index_y][index_x];
		if (cell != '1' && cell != 'E')
		{
			enemy->x = index_x * CELL_SIZE;
			enemy->y = index_y * CELL_SIZE;
		}
		count++;
	}
}
