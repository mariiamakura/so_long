/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:22:29 by mparasku          #+#    #+#             */
/*   Updated: 2023/05/03 16:09:26 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"

#define WIDTH 256
#define HEIGHT 256

//content struct
typedef struct s_game_content
{
	char			**grid;
	size_t			width;
	size_t			height;
	size_t			coins;
	size_t			steps;
	size_t			collected;
	size_t			link_x;
	size_t			link_y;
	size_t			exit_x;
	size_t			exit_y;
	//mlx_texture_t	*link_up;
	//mlx_texture_t	*link_down;
	//mlx_texture_t	*link_left;
	//mlx_texture_t	*link_right;
	//t_img			*img;
	mlx_t			*mlx;
}	t_game_content;



//so_long.c
void	map_validation(char *map);

//error.c
void	error_msg(char *str);

//map_extention_check.c
void	check_map_extension(char *file);
void	map_is_empty(char *map);
void	map_has_empty_lines(char *map);

//map_reading.c
char	*map_file_to_str(char *map);

//map_content_check.c
void	map_content_check(char *map);
void	invalid_content(int i);

#endif
