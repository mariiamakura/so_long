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
    printf("width: %d\n", game->width);
    printf("height: %d\n", game->height);
    printf("steps: %d\n", game->steps);
    printf("coins: %d\n", game->coins);
    printf("player_x: %d\n", game->player->position.x);
    printf("player_y: %d\n", game->player->position.y);
    printf("exit_x: %d\n", game->exit_position.x);
    printf("exit_y: %d\n", game->exit_position.y);
}

//pass searching algorithm
/*
#include <stdio.h>

typedef struct s_game
{
    char            **grid;
    int coins;
    int exit_x;
}    t_game;

int path_check_algo(t_game *temp, int y, int x)
{
    if (temp->grid[y][x] == '1')
        return (0);
    if (temp->grid[y][x] == 'C')
        temp->coins--;
    if (temp->grid[y][x] == 'E')
    {
        temp->exit_x = 1;
        return (0);
    }
    temp->grid[y][x] = '1';
    if (path_check_algo(temp, y + 1, x))
        return (1);
    if (path_check_algo(temp, y - 1, x))
        return (1);
    if (path_check_algo(temp, y, x + 1))
        return (1);
    if (path_check_algo(temp, y, x - 1))
        return (1);
    return (0);
}


int main() {
    t_game *temp = malloc(sizeof(t_game));  // Allocate memory for temp
    if (temp == NULL) {
        // Handle memory allocation failure
        return 1;
    }

    char new_grid[4][5] = {
            {'1', '1', '1', '1', '1'},
            {'1', 'P', '0', 'C', '1'},
            {'1', 'C', '0', 'E', '1'},
            {'1', '1', '1', '1', '1'}
    };

    temp->grid = malloc(4 * sizeof(char *));
    if (temp->grid == NULL) {
        // Handle memory allocation failure
        free(temp);
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        temp->grid[i] = malloc(5 * sizeof(char));
        if (temp->grid[i] == NULL) {
            // Handle memory allocation failure
            for (int j = 0; j < i; j++) {
                free(temp->grid[j]);
            }
            free(temp->grid);
            free(temp);
            return 1;
        }
        memcpy(temp->grid[i], new_grid[i], 5 * sizeof(char));
    }

    temp->coins = 2;  // Initialize coins
    temp->exit_x = 0; // Initialize exit_x

    path_check_algo(temp, 1, 1);

    // Free allocated memory
    for (int i = 0; i < 4; i++) {
        free(temp->grid[i]);
    }
    free(temp->grid);
    free(temp);

    return 0;
}*/
