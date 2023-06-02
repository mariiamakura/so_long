#include "../include/so_long.h"

void choose_images(t_game *game, size_t y, size_t x)
{
    if (game->grid[y][x] == '1')
        if (mlx_image_to_window(game->mlx, game->img->bush,
                                x * PIXELS, y * PIXELS) < 0)
            error_msg("Failed to put bushes to window");
    if (game->grid[y][x] == 'C')
        if (mlx_image_to_window(game->mlx, game->img->coins,
                                x * PIXELS, y * PIXELS) < 0)
            error_msg("Failed to put sushi to window");
    if (game->grid[y][x] == 'P')
        if (mlx_image_to_window(game->mlx, game->img->player,
                                x * PIXELS, y * PIXELS) < 0)
            error_msg("Failed to put player to window");
    if (game->grid[y][x] == 'E')
        if (mlx_image_to_window(game->mlx, game->img->exit_closed,
                                x * PIXELS, y * PIXELS) < 0)
            error_msg("Failed to put closed exit to window");
    if (game->grid[y][x] == 'X')
        if (mlx_image_to_window(game->mlx, game->img->enemy,
                                x * PIXELS, y * PIXELS) < 0)
            error_msg("Failed to put enemies to window");
}

void    fill_background(t_game *game)
{
    size_t x;
    size_t  y;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (mlx_image_to_window(game->mlx, game->img->floor,
                                    x * PIXELS, y * PIXELS) < 0)
                error_msg("Failed to put image to window");
            x++;
        }
        y++;
    }
}

void put_images(t_game *game)
{
    size_t y;
    size_t x;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            choose_images(game, y, x);
            x++;
        }
        y++;
    }
}