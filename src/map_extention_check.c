/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:22:19 by mparasku          #+#    #+#             */
/*   Updated: 2023/05/03 15:19:01 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_extension(char *file)
{
	if (ft_str_ends_with(file, ".ber"))
		error_msg("Wrong map extension. Provide .ber");
}

void	map_is_empty(char *map)
{
	if (!map[0])
		error_msg("Map is empty");
}

void	map_has_empty_lines(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' &&map[i + 1] == '\n'))
			error_msg("Map has empty lines");
		i++;
	}
}