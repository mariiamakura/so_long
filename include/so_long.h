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
#include "../lib/libft/libft.h"

# define CELL_SIZE 64
# define ELOOP 100

typedef struct s_point {
    int32_t x;
    int32_t y;
} t_point;

//for random movements of enemies
typedef struct s_var {
    int				run_x;
    int				run_y;
    int				*x;
    int				*y;
    int				index_x;
    int				index_y;
}	t_var;

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
    mlx_image_t *moves_print;
    mlx_image_t *moves_num;
    mlx_image_t *coins_num;
} t_img;

typedef struct s_player {
    t_point position;
} t_player;

//content struct
typedef struct s_game {
    char **grid;
    size_t width;
    size_t height;
    size_t coins;
    size_t steps;
    size_t collected;
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
size_t row_count(char **map_as_arr);

size_t count_coins(t_game *game);

t_point coordinates(char item, t_game *game);

//path_check.c
void path_check_begin(t_game *game);

int path_check_algo(t_game *temp, size_t x, size_t y);

void free_game_struct_copy(char **grid, size_t height);

//fill_map_with_image.c
void    fill_background(t_game *game);
void put_images(t_game *game);
void choose_images(t_game *game, size_t y, size_t x);

//score_to_image.c
void score_to_image(t_game *game);
void print_coins(t_game *game);
void print_moves(t_game *game);
void check_game_status(t_game *game);

//moves.c
void process_key_callback(mlx_key_data_t key_data, void *data);

//enemy.c
void enemy_patrol(void *temp);
void check_status(const t_game *game);
void move_enemy(const t_game *game, int count);

//MY PRINTS DELETE
void print_struct_content(t_game *game);
void print_2d_array(char **map_as_arr);
//+pass searching algorithm



#endif
