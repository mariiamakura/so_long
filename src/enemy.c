#include "../include/so_long.h"

void enemy_patrol(t_game *game) {
    int count = 0;
    while (count < game->img->enemy->count) {
        mlx_instance_t *enemy = &game->img->enemy->instances[count];
        int runX = rand() % 3 - 1; // -1, 0, 1
        int runY = rand() % 3 - 1; // -1, 0, 1
        int indexX = enemy->x / CELL_SIZE + runX;
        int indexY = enemy->y / CELL_SIZE + runY;
        char cell = game->grid[indexY][indexX];
        if (cell != '1' && cell != 'E') {
            enemy->x = indexX * CELL_SIZE;
            enemy->y = indexY * CELL_SIZE;
        }
        count++;
    }
}