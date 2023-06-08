/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:22:29 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/08 19:28:15 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TICK_DELAY 0.1 //s
# define PLAYER_DELAY 3 //s
# define ENEMY_DELAY 10 //s
# define CELL_SIZE 64


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"
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
void	creating_visual(t_game *game);


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
void	are_walls(t_game *game);
void	is_vertical(t_game *game);
void	is_horizontal(t_game *game);

//struct_init.c
t_game	*initialize_game(char **map_as_arr);

//count_map.c
u_int16_t	row_count(char **map_as_arr);
u_int16_t	count_coins(t_game *game);
t_point	coordinates(char item, t_game *game);

//path_check.c
void	path_check_begin(t_game *game);
int		path_check_algo(t_game *temp, u_int16_t x, u_int16_t y);
void 	free_game_struct_copy(char **grid, u_int16_t height);

//load_basic_sprites.c
t_img	*initialize_image_struct(mlx_t *mlx);
void	load_exit_closed_texture(mlx_t *mlx, t_img *img);
void	load_exit_opened_texture(mlx_t *mlx, t_img *img);

//load_texture.c
void	load_floor_texture(mlx_t *mlx, t_img *img);
void	load_bush_texture(mlx_t *mlx, t_img *img);
void	load_coins_texture(mlx_t *mlx, t_img *img);
void	load_player_texture(mlx_t *mlx, t_img *img);
void	load_enemy_texture(mlx_t *mlx, t_img *img);

//fill_map_with_image.c
void	fill_background(t_game *game);
void	put_images(t_game *game);
void	choose_images(t_game *game, u_int16_t y, u_int16_t x);

//process_image.c
void	process_key_callback(mlx_key_data_t key_data, void *data);
void	process_window_keys(t_game *game, mlx_key_data_t key_data);
void	process_player_movement_keys(t_game *game, mlx_key_data_t key_data);
void	process_player_movement(t_game *game, t_point direction);

//moves.c
void remove_coin(t_game *game, t_point position);
void move_player(t_game *game, t_point position);
void player_animation(t_game *game, t_point direction);

//free_structs.c
void free_grid(t_game *game);
void free_game(t_game *game);
void delete_image(t_game *game);

//update_loop.c
void	mlx_loop_hook_callback(void *param);
void	tick_callback(t_game *game);
void	enemy_patrol(t_game *game, int run_x, int run_y);


//repaint.c
void repaint_status_bar(t_game *game);
void check_game_status(t_game *game);



//MY PRINTS DELETE
void print_struct_content(t_game *game);
void print_2d_array(char **map_as_arr);
//+pass searching algorithm



#endif
