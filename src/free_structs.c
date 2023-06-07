/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:21:36 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/07 14:37:25 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/update_loop.h"

void free_grid(t_game *game)
{
	if (game->grid != NULL) {
    int i = 0;
    while (i < game->height) {
        free(game->grid[i]);
        i++;
    }
    free(game->grid);
	}
}

void delete_image(t_game *game)
{
	mlx_delete_image(game->mlx, game->img->floor);
	mlx_delete_image(game->mlx, game->img->bush);
	mlx_delete_image(game->mlx, game->img->coins);
	mlx_delete_image(game->mlx, game->img->player);
	mlx_delete_image(game->mlx, game->img->enemy);
	mlx_delete_image(game->mlx, game->img->exit_closed);
	mlx_delete_image(game->mlx, game->img->enemy);
	mlx_delete_image(game->mlx, game->img->moves_label);
	mlx_delete_image(game->mlx, game->img->moves_text);
	mlx_delete_image(game->mlx, game->img->coins_label);
	mlx_delete_image(game->mlx, game->img->coins_text);
	mlx_delete_texture(game->img->player_down);
	mlx_delete_texture(game->img->player_left);
	mlx_delete_texture(game->img->player_right);
	mlx_delete_texture(game->img->player_up);
	free(game->img);
	game->img = NULL;
}

void free_game(t_game *game)
{
	if (game == NULL) {
        return;
    }
	free_grid(game);
	
	if (game->player != NULL)
		free(game->player); //maybe i should free futher in player struct
	
	delete_image(game);

	if (game->mlx != NULL)
		free(game->mlx);
	
	free(game);
	game = NULL;
}