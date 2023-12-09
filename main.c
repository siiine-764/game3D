/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:12:15 by hben-mes          #+#    #+#             */
/*   Updated: 2023/12/09 05:10:59 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
