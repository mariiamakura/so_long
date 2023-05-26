/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:22:29 by mparasku          #+#    #+#             */
/*   Updated: 2023/05/05 15:03:46 by mparasku         ###   ########.fr       */
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
typedef struct s_game
{
	char			**grid;
	size_t			width;
	size_t			height;
	size_t			coins;
	size_t			steps;
	size_t			collected;
	size_t			player_x; //link_x
	size_t			player_y; //link_y
	size_t			exit_x;
	size_t			exit_y;
	//mlx_texture_t	*link_up;
	//mlx_texture_t	*link_down;
	//mlx_texture_t	*link_left;
	//mlx_texture_t	*link_right;
	//t_img			*img;
	mlx_t			*mlx;
}	t_game;



//so_long.c
t_game	*map_validation(char *map);
void creating_visual(t_game *game);


//error.c
void	error_msg(char *str);

//map_extention_check.c
void	check_map_extension(char *file);
void	map_is_empty(char *map);
void	map_has_empty_lines(char *map);
void	map_shape_check(char **map_arr);

//map_reading.c
char	*map_file_to_str(char *map);

//map_content_check.c
void	map_content_check(char *map);
void	invalid_content(int i);
void    are_walls(t_game *game);
void    is_vertical(t_game *game);
void    is_horizontal(t_game *game);

//struct_init.c
t_game *initialize_game(char **map_as_arr);

//count_map.c
size_t row_count(char **map_as_arr);
size_t count_coins(t_game *game);
size_t coordinates(char item, t_game *game, char coordinate_c);

//path_check.c
void path_check_begin(t_game *game);
int path_check_algo(t_game *temp, size_t y, size_t x);
void free_game_struct_copy(char **grid, size_t height);

//MY PRINTS DELETE
void print_struct_content(t_game *game);
void print_2d_array(char **map_as_arr);

#endif
