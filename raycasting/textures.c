/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:07:22 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 03:57:04 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
void	get_textures(t_map *map)
{
	char	*str;

	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	str = ft_strtrim("textures/wall_4.png", "\n");
	map->no = mlx_load_png(str);
	free(str);
	str = ft_strtrim("textures/wall_3.png", "\n");
	map->so = mlx_load_png(str);
	free(str);
	str = ft_strtrim("textures/wall_2.png", "\n");
	map->ea = mlx_load_png(str);
	free(str);
	str = ft_strtrim("textures/wall_1.png", "\n");
	map->we = mlx_load_png(str);
	free(str);

}