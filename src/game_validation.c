#include "../include/so_long.h"

void check_enemy_status(t_game *game);

void check_exit_status(t_game *game);

void check_game_status(t_game *game) {
    check_enemy_status(game);
    check_exit_status(game);
}

void check_enemy_status(t_game *game) {
    int32_t player_x = game->player->position.x * CELL_SIZE;
    int32_t player_y = game->player->position.y * CELL_SIZE;

    int index = 0;
    while (index < game->img->enemy->count) {
        mlx_instance_t enemy_instance = game->img->enemy->instances[index];
        if (player_x == enemy_instance.x && player_y == enemy_instance.y) {
            mlx_close_window(game->mlx);
            write(1, "You were eaten :(\n", 18);
        }
        index++;
    }
}

void check_exit_status(t_game *game) {
    t_point exit_position = game->exit_position;
    t_point player_position = game->player->position;
    int32_t exit_x = exit_position.x * CELL_SIZE;
    int32_t exit_y = exit_position.y * CELL_SIZE;

    if (game->collected == game->coins) {
        if (mlx_image_to_window(game->mlx, game->img->exit_opened, exit_x, exit_y) < 0) {
            error_msg("Failed to put opened exit to window");
        }
        game->grid[exit_position.y][exit_position.x] = '0';
        if (player_position.x == exit_position.x && player_position.y == exit_position.y) {
            mlx_close_window(game->mlx);
            write(1, "Congratulations!\n", 17);
            write(1, "You ate all sushi!\n", 19);
        }
    }
}
