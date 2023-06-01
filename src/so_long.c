/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:22:17 by mparasku          #+#    #+#             */
/*   Updated: 2023/05/05 15:03:57 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


t_game	*map_validation(char *map)
{
	char	*map_as_str;
	char	**map_as_arr;
    t_game  *game;

	check_map_extension(map);
	map_as_str = map_file_to_str(map);
	map_is_empty(map_as_str);
	map_has_empty_lines(map_as_str);
	map_content_check(map_as_str);
	map_as_arr = ft_split(map_as_str, '\n');
	free(map_as_str);
	map_shape_check(map_as_arr);
    game = initialize_game(map_as_arr); //grid points to map_as_arr so NO free
    are_walls(game);
    path_check_begin(game);
    return (game);
}

/*void creating_visual(t_game *game)
{

}*/

int	main(int argc, char **argv)
{
    t_game *game;
    t_img *image;

	if (argc != 2)
		error_msg("Just give me a map! :(");
	game = map_validation(argv[1]);
    game->mlx = mlx_init(game->width * PIXELS, game->height * PIXELS,
                         "so_long", false);
    if (!game->mlx)
        return (EXIT_FAILURE);
    image = initialize_image_struct(game->mlx); //not finished
    game->img = image;
    fill_background(game);
    //
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);

    //print_struct_content(game);
}