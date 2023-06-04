#include "../include/so_long.h"

void process_window_keys(t_game *game, mlx_key_data_t key_data);

void process_player_movement_keys(t_game *game, mlx_key_data_t key_data);

void remove_coin(t_game *game, t_point position);

void move_player(t_game *game, t_point position);

void process_player_movement(t_game *game, t_point direction);

void player_animation(t_game *game, t_point direction);

void process_key_callback(mlx_key_data_t key_data, void *data) {
    t_game *game = (t_game *) data;
    process_window_keys(game, key_data);
    process_player_movement_keys(game, key_data);
}

void process_window_keys(t_game *game, mlx_key_data_t key_data) {
    if (key_data.action == MLX_PRESS && key_data.key == MLX_KEY_ESCAPE)
        mlx_close_window(game->mlx);
}

void process_player_movement_keys(t_game *game, mlx_key_data_t key_data) {
    t_point direction = {0, 0};

    if (key_data.action == MLX_PRESS) {
        if (key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP) {
            direction.y = -1;
            process_player_movement(game, direction);
        } else if (key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN) {
            direction.y = 1;
            process_player_movement(game, direction);
        } else if (key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT) {
            direction.x = 1;
            process_player_movement(game, direction);
        } else if (key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT) {
            direction.x = -1;
            process_player_movement(game, direction);
        }
    }
}

void process_player_movement(t_game *game, t_point direction) {
    t_point old_position = game->player->position;
    t_point new_position = {old_position.x + direction.x, old_position.y + direction.y};

    char map_cell = game->grid[new_position.y][new_position.x];
    if (map_cell == 'C') {
        remove_coin(game, new_position);
    }
    if (map_cell != '1' && map_cell != 'E') {
        move_player(game, new_position);
    }
    player_animation(game, direction);

    check_game_status(game);
}

void remove_coin(t_game *game, t_point position) {
    int32_t x = position.x * CELL_SIZE;
    int32_t y = position.y * CELL_SIZE;

    int index = 0;
    while (index < game->img->coins->count) {
        mlx_instance_t *instance = &game->img->coins->instances[index];
        if (instance->x == x && instance->y == y) {
            instance->enabled = false;
        }
        index++;
    }
    game->grid[position.y][position.x] = '0';
    game->collected += 1;
}

void move_player(t_game *game, t_point position) {
    int32_t x = position.x * CELL_SIZE;
    int32_t y = position.y * CELL_SIZE;

    game->player->position = position;
    game->img->player->instances[0].x = x;
    game->img->player->instances[0].y = y;
    game->steps += 1;
}

void player_animation(t_game *game, t_point direction) {
    if (direction.y < 0) {
        mlx_draw_texture(game->img->player, game->img->player_up, 0, 0);
    } else if (direction.y > 0) {
        mlx_draw_texture(game->img->player, game->img->player_down, 0, 0);
    } else if (direction.x > 0) {
        mlx_draw_texture(game->img->player, game->img->player_right, 0, 0);
    } else if (direction.x < 0) {
        mlx_draw_texture(game->img->player, game->img->player_left, 0, 0);
    }
}
