
#include "cub3d.h"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
	if (ac != 2)
	{
		printf("Error\nTwo arguments is requirred\n");
		return (1);
	}
    args_check(av[1]);
    t_map *map = malloc(sizeof(t_map));
    map_reader(av[1], map);
    check_map(map->mapa);
    check_color(map);
    ft_position_player(map);
    get_textures(map);
    int bl = ft_init(map);
    free (map);
    return (bl);
}
