#include "../include/so_long.h"

void    check_map_extension(char *file)
{
    if (ft_str_ends_with(file, ".ber"))
        error_msg("Wrong map extension. Provide .ber");
}