/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:21:36 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/09 13:52:09 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_grid(t_game *game)
{
	int	i;

	i = 0;
	if (game->grid != NULL)
	{
		while (i < game->height)
		{
			free(game->grid[i]);
			i++;
		}
		free(game->grid);
	}
}

void	delete_image(t_game *game)
{
	mlx_delete_texture(game->img->player_down);
	mlx_delete_texture(game->img->player_left);
	mlx_delete_texture(game->img->player_right);
	mlx_delete_texture(game->img->player_up);
	free(game->img);
	game->img = NULL;
}

void	free_game(t_game *game)
{
	if (game == NULL)
		return ;
	free_grid(game);
	if (game->player != NULL)
		free(game->player);
	delete_image(game);
	free(game);
	game = NULL;
}
