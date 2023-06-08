/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:18:19 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/08 18:32:03 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	process_key_callback(mlx_key_data_t key_data, void *data)
{
	t_game	*game;

	game = (t_game *) data;
	process_window_keys(game, key_data);
	process_player_movement_keys(game, key_data);
}

void	process_window_keys(t_game *game, mlx_key_data_t key_data)
{
	if (key_data.action == MLX_PRESS && key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}

void	process_player_movement_keys(t_game *game, mlx_key_data_t key_data)
{
	t_point	direction;

	direction.x = 0;
	direction.y = 0;
	if (key_data.action == MLX_PRESS)
	{
		if (key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP)
			direction.y = -1;
		else if (key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN)
			direction.y = 1;
		else if (key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT)
			direction.x = 1;
		else if (key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT)
			direction.x = -1;
		process_player_movement(game, direction);
	}
}

void	process_player_movement(t_game *game, t_point direction)
{
	t_point	old_position;
	t_point	new_position;
	char	map_cell;

	old_position = game->player->position;
	new_position.x = old_position.x + direction.x;
	new_position.y = old_position.y + direction.y;
	map_cell = game->grid[new_position.y][new_position.x];
	if (map_cell == 'C')
		remove_coin(game, new_position);
	if (map_cell != '1' && map_cell != 'E')
		move_player(game, new_position);
	player_animation(game, direction);
	check_game_status(game);
}
