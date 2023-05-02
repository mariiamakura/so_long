#include "../include/so_long.h"


void map_validation(char *map)
{
    check_map_extension(map);
}
int main(int argc, char **argv)
{
    if (argc != 2)
        error_msg("Just give me a map! :(");
    map_validation(argv[1]);
}