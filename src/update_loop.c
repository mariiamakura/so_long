#include "../include/so_long.h"

#define TICK_DELAY 0.1 //s
#define PLAYER_DELAY 3 //s
#define ENEMY_DELAY 10 //s

void tick_callback(t_game *game);

void mlx_loop_hook_callback(void *param) {
    t_game *game = (t_game *) param;

    static double tick_elapsed_time = 0.0;

    tick_elapsed_time += game->mlx->delta_time;

    if (tick_elapsed_time > TICK_DELAY) {
        tick_elapsed_time -= TICK_DELAY;
        tick_callback(game);
    }
}

void tick_callback(t_game *game) {
    static int player_elapsed_tick = 0;
    static int enemy_elapsed_tick = 0;

    player_elapsed_tick++;
    enemy_elapsed_tick++;

    if (player_elapsed_tick > PLAYER_DELAY) {
        player_elapsed_tick -= PLAYER_DELAY;
    }
    if (enemy_elapsed_tick > ENEMY_DELAY) {
        enemy_elapsed_tick -= ENEMY_DELAY;
        enemy_patrol(game);
    }
    repaint_status_bar(game);
    check_game_status(game);
}
