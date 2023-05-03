/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:22:17 by mparasku          #+#    #+#             */
/*   Updated: 2023/05/03 16:13:55 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	map_validation(char *map)
{
	char	*map_as_str;
	char	**map_as_arr;

	check_map_extension(map);
	map_as_str = map_file_to_str(map);
	map_is_empty(map_as_str);
	map_has_empty_lines(map_as_str);
	map_content_check(map_as_str);
	map_as_arr = ft_split(map_as_str, '\n');
	free(map_as_str);
	
/* 	int i = 0;
	while (i++ > 7 && map_as_arr[i])
		printf("%s\n", map_as_arr[i]); */

}
int	main(int argc, char **argv)
{
	if (argc != 2)
		error_msg("Just give me a map! :(");
	map_validation(argv[1]);
}