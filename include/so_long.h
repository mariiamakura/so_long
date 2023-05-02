#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../printf/includes/ft_printf.h"

#define WIDTH 256
#define HEIGHT 256

//so_long.c
void map_validation(char *map);

//error_check.c
void    error_msg(char *str);

//map_check.c
void    check_map_extension(char *file);

#endif
