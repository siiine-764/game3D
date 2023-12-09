/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:09:20 by hben-mes          #+#    #+#             */
/*   Updated: 2023/12/09 12:09:24 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_map	*map;
	int		bl;

	(void)ac;
	(void)av;
	if (ac != 2)
	{
		printf("Error\nTwo arguments is requirred\n");
		return (1);
	}
	args_check(av[1]);
	map = malloc(sizeof(t_map));
	map_reader(av[1], map);
	check_map(map->mapa);
	check_color(map);
	ft_position_player(map);
	get_textures(map);
	bl = ft_init(map);
	free(map);
	return (bl);
}
