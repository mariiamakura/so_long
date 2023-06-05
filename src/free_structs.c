/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:21:36 by mparasku          #+#    #+#             */
/*   Updated: 2023/06/05 15:34:07 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/update_loop.h"

void free_grid(t_game *game)
{
	if (game->grid != NULL) {
    int i = 0;
    while (i < game->height) {
        free(game->grid[i]);
        i++;
    }
    free(game->grid);
}

}

void free_game(t_game *game)
{
	if (game == NULL) {
        return;
    }
	free_grid(game);
	
	if (game->player != NULL)
		free((*t_game)game->player->position);
		
}