/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:25:12 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/08 18:05:16 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*map_file_to_str(char *map)
{
	char	*one_line;
	char	*all_lines_joined;
	int		fd;

	all_lines_joined = ft_calloc(1, 1);
	if (!all_lines_joined)
		return (NULL);
	fd = open(map, O_RDONLY);
	one_line = get_next_line(fd);
	while (one_line)
	{
		all_lines_joined = ft_strjoin(all_lines_joined, one_line);
		free(one_line);
		one_line = get_next_line(fd);
	}
	close(fd);
	free(one_line);
	return (all_lines_joined);
}
