#include "../include/so_long.h"

void remove_coins(t_game *game, int y,int x)
{
    int coins_i;

    coins_i = 0;
    y = y * 64; //+16?
    x = x * 64; //+16?
    while(coins_i < game->img->coins->count)
    {
        if (game->img->coins->instances[coins_i]. x == x
        && game->img->coins->instances[coins_i].y == y)
        {
            game->img->coins->instances[coins_i].enabled = false;
        }
        coins_i++;
    }
}

t_game *move_up(t_game *game)
{
    if (game->grid[game->player_y - 1][game->player_x] != '1' &&
            game->grid[game->player_y - 1][game->player_x] != 'E')
    {
        if (game->grid[game->player_y - 1][game->player_x] == 'C')
        {
            remove_coins(game, game->player_y - 1, game->player_x);
            print_coins(game);
            game->grid[game->player_y - 1][game->player_x] = '0';
            game->collected += 1;
        }
        game->player_y -= 1;
        game->img->player->instances[0].y -= 1 * CELL_SIZE;
        game->steps += 1;
    }
    check_game_status(game);
    return (game);
}

t_game *move_down(t_game *game)
{
    if (game->grid[game->player_y + 1][game->player_x] != '1' &&
        game->grid[game->player_y + 1][game->player_x] != 'E')
    {
        if (game->grid[game->player_y + 1][game->player_x] == 'C')
        {
            remove_coins(game, game->player_y + 1, game->player_x);
            print_coins(game);
            game->grid[game->player_y + 1][game->player_x] = '0';
            game->collected += 1;
        }
        game->player_y += 1;
        game->img->player->instances[0].y += 1 * CELL_SIZE;
        game->steps += 1;
    }
    check_game_status(game);
    return (game);
}

t_game *move_right(t_game *game)
{
    if (game->grid[game->player_y][game->player_x + 1] != '1' &&
        game->grid[game->player_y][game->player_x + 1] != 'E')
    {
        if (game->grid[game->player_y][game->player_x + 1] == 'C')
        {
            remove_coins(game, game->player_y, game->player_x + 1);
            print_coins(game);
            game->grid[game->player_y][game->player_x + 1] = '0';
            game->collected += 1;
        }
        game->player_x += 1;
        game->img->player->instances[0].x += 1 * CELL_SIZE;
        game->steps += 1;
    }
    check_game_status(game);
    return (game);
}

t_game *move_left(t_game *game)
{
    if (game->grid[game->player_y][game->player_x - 1] != '1' &&
        game->grid[game->player_y][game->player_x - 1] != 'E')
    {
        if (game->grid[game->player_y][game->player_x - 1] == 'C')
        {
            remove_coins(game, game->player_y, game->player_x - 1);
            print_coins(game);
            game->grid[game->player_y][game->player_x - 1] = '0';
            game->collected += 1;
        }
        game->player_x -= 1;
        game->img->player->instances[0].x -= 1 * CELL_SIZE;
        game->steps += 1;
    }
    check_game_status(game);
    return (game);
}