/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:22:29 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/07 14:36:24 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"

# define CELL_SIZE 64

typedef struct s_point {
    int32_t x;
    int32_t y;
} t_point;

//image struct
typedef struct s_img
{
    mlx_image_t *floor;
    mlx_image_t *bush;
    mlx_image_t *coins;
    mlx_image_t *player;
    mlx_texture_t *player_up;
    mlx_texture_t *player_down;
    mlx_texture_t *player_left;
    mlx_texture_t *player_right;
    mlx_image_t *enemy;
    mlx_image_t *exit_closed;
    mlx_image_t *exit_opened;
    mlx_image_t *moves_label;
    mlx_image_t *moves_text;
    mlx_image_t *coins_label;
    mlx_image_t *coins_text;
} t_img;

typedef struct s_player {
    t_point position;
} t_player;

//content struct
typedef struct s_game {
    char **grid;
    u_int16_t width;
    u_int16_t height;
    u_int16_t coins;
    u_int16_t steps;
    u_int16_t collected;
    t_player *player;
    t_point exit_position;
    t_img *img;
    mlx_t *mlx;
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

t_img *initialize_image_struct(mlx_t *mlx);

//count_map.c
u_int16_t row_count(char **map_as_arr);

u_int16_t count_coins(t_game *game);

t_point coordinates(char item, t_game *game);

//path_check.c
void path_check_begin(t_game *game);

int path_check_algo(t_game *temp, u_int16_t x, u_int16_t y);

void free_game_struct_copy(char **grid, u_int16_t height);

//fill_map_with_image.c
void    fill_background(t_game *game);
void put_images(t_game *game);
void choose_images(t_game *game, u_int16_t y, u_int16_t x);

//repaint.c
void repaint_status_bar(t_game *game);

void check_game_status(t_game *game);

//moves.c
void process_key_callback(mlx_key_data_t key_data, void *data);

//enemy.c
void enemy_patrol(t_game *game);

//free_structs.c
void free_grid(t_game *game);
void free_game(t_game *game);
void delete_image(t_game *game);

//MY PRINTS DELETE
void print_struct_content(t_game *game);
void print_2d_array(char **map_as_arr);
//+pass searching algorithm



#endif
