/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:46:03 by mparasku          #+#    #+#             */
/*   Updated: 2023/05/03 15:58:34 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	invalid_content(int i)
{
	//X -for enemies
	if (!ft_strchr("01PECX\n", i))
	{
		error_msg("Invalid characters");
	}
	
}

void	map_content_check(char *map)
{
	int	player;
	int	exit;
	int	coins;
	int	i;
	
	player = 0;
	exit = 0;
	coins = 0;
	i = 0;
	while(map[i])
	{
		if (map[i] == 'P')
			player++;
		else if (map[i] == 'E')
			exit++;
		else if (map[i] == 'C')
			coins++;
		else
			invalid_content(map[i]);
		i++;
	}
	if (player != 1 || exit != 1 || coins < 1)
		error_msg("Error in content quantity");
}

void is_vertical(t_game *game)
{
    u_int16_t  i;

    i = 0;
    while (game->grid[i])
    {
        if (game->grid[i][0] != '1')
            error_msg("The map has empty space in walls");
        if (game->grid[i][game->width - 1] != '1')
            error_msg("The map has empty space in walls");
        i++;
    }
}

void is_horizontal(t_game *game)
{
    u_int16_t i;

    i = 0;
    while (game->grid[0][i])
    {
        if (game->grid[0][i] != '1')
            error_msg("The map has empty space in walls");
        if (game->grid[game->height - 1][0] != '1')
            error_msg("The map has empty space in walls");
        i++;
    }
}

void are_walls(t_game *game)
{
    is_vertical(game);
    is_horizontal(game);
}