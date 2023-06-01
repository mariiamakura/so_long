#include "../include/so_long.h"

t_img *load_floor_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t *floor;

    floor = mlx_load_png("./sprites/floor.png");
    if (!floor)
        error_msg("Floor sprite couldn't be loaded");
    img->floor = mlx_texture_to_image(mlx, floor);
    if (!img->floor)
        error_msg("Problem with floor texture to image");
    mlx_delete_texture(floor);
    return (img);
}