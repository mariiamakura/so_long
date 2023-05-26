#include "../include/so_long.h"

void print_2d_array(char **map_as_arr)
{
    int i = 0;
    while (i++ < 7 && map_as_arr[i])
        printf("%s\n", map_as_arr[i]);
    printf("im here");
}

void print_struct_content(t_game *game)
{
    printf("width: %zu\n", game->width);
    printf("height: %zu\n", game->height);
    printf("steps: %zu\n", game->steps);
    printf("coins: %zu\n", game->coins);
    printf("player_x: %zu\n", game->player_x);
    printf("player_y: %zu\n", game->player_y);
    printf("exit_x: %zu\n", game->exit_x);
    printf("exit_y: %zu\n", game->exit_y);
}