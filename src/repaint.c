/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repaint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:35:13 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/09 13:38:15 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	repaint_status_bar(t_game *game)
{
	repaint_coins(game);
	repaint_moves(game);
}

void	repaint_moves(t_game *game)
{
	char	*str;
	int32_t	status_bar_y;

	str = ft_itoa(game->steps);
	status_bar_y = game->height * CELL_SIZE - CELL_SIZE * 2 / 3;
	mlx_delete_image(game->mlx, game->img->moves_label);
	mlx_delete_image(game->mlx, game->img->moves_text);
	game->img->moves_label = mlx_put_string(game->mlx, "MOVES:",
			16, status_bar_y);
	game->img->moves_text = mlx_put_string(game->mlx, str, 80, status_bar_y);
	free(str);
}

void	repaint_coins(t_game *game)
{
	char	*str;
	int32_t	status_bar_y;

	str = ft_itoa(game->collected);
	status_bar_y = game->height * CELL_SIZE - CELL_SIZE * 2 / 3;
	mlx_delete_image(game->mlx, game->img->coins_label);
	mlx_delete_image(game->mlx, game->img->coins_text);
	game->img->coins_label = mlx_put_string(game->mlx, "SUSHI:",
			160, status_bar_y);
	game->img->coins_text = mlx_put_string(game->mlx, str, 224, status_bar_y);
	free(str);
}
