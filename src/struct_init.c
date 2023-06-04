#include "../include/so_long.h"

t_game *initialize_game(char **map_as_arr)
{
    t_game *game = (t_game *) ft_calloc(1, sizeof(t_game));
    if (!game) {
        error_msg("game struct allocation failed");
    }

    game->width = ft_strlen(map_as_arr[0]);
    game->height = row_count(map_as_arr);
    game->grid = map_as_arr;
    game->steps = 0;
    game->coins = count_coins(game);
    if (!(game->player = (t_player *) ft_calloc(1, sizeof(t_player)))) {
        error_msg("game player allocation failed");
    }
    game->player->position = coordinates('P', game);
    game->exit_position = coordinates('E', game);
    return (game);
}