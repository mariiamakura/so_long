#include "../include/so_long.h"

void check_game_status(t_game *game) {
    t_point player_position = game->player->position;
    t_point exit_position = game->exit_position;
    int32_t x = exit_position.x * CELL_SIZE;
    int32_t y = exit_position.y * CELL_SIZE;

    if (game->collected == game->coins) {
        if (mlx_image_to_window(game->mlx, game->img->exit_opened, x, y) < 0) {
            error_msg("Failed to put opened exit to window");
        }
        game->grid[exit_position.y][exit_position.x] = '0';
        if (player_position.x == exit_position.x && player_position.y == exit_position.y) {
            mlx_close_window(game->mlx);
            write(1, "Congratulations!\n", 18);
            write(1, "You ate all sushi!\n", 20);
        }
    }
}