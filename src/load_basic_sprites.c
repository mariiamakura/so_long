/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_basic_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:37:03 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/08 17:58:44 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	*initialize_image_struct(mlx_t *mlx)
{
	t_img	*image;

	image = (t_img *) ft_calloc(1, sizeof(t_img));
	if (image == NULL)
		return (NULL);
	load_floor_texture(mlx, image);
	load_bush_texture(mlx, image);
	load_coins_texture(mlx, image);
	load_player_texture(mlx, image);
	load_enemy_texture(mlx, image);
	load_exit_closed_texture(mlx, image);
	load_exit_opened_texture(mlx, image);
	return (image);
}

void	load_exit_closed_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./sprites/exit_closed.png");
	if (exit == NULL)
		error_msg("Exit closed sprite couldn't be loaded");
	img->exit_closed = mlx_texture_to_image(mlx, exit);
	if (img->exit_closed == NULL)
		error_msg("Problem with closed exit texture to image");
	mlx_delete_texture(exit);
}

void	load_exit_opened_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./sprites/exit_opened.png");
	if (exit == NULL)
		error_msg("Exit opened sprite couldn't be loaded");
	img->exit_opened = mlx_texture_to_image(mlx, exit);
	if (img->exit_opened == NULL)
		error_msg("Problem with opened exit texture to image");
	mlx_delete_texture(exit);
}
