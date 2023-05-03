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