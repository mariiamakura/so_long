#include "../include/so_long.h"

t_game *initialize_game(char **map_as_arr)
{
    t_game *game;

    game = (t_game *) ft_calloc(1, sizeof(t_game));
    if (!game)
        error_msg("game struct allocation failed");
    game->width = ft_strlen(map_as_arr[0]);
    game->height = row_count(map_as_arr);
    game->grid = map_as_arr;
    game->steps = 0;
    game->coins = count_coins(game);
    game->player_x = coordinates('P', game, 'x');
    game->player_y = coordinates('P', game, 'y');
    game->exit_x = coordinates('E', game, 'x');
    game->exit_y = coordinates('E', game, 'y');
    //load player texture
    return (game);
}

t_img *initialize_image_struct(mlx_t *mlx)
{
    t_img *image;

    image = (t_img *) ft_calloc(1, sizeof(t_img));
    if (!image)
        return (NULL);
    image = load_floor_texture(mlx, image);
    return (image);
}