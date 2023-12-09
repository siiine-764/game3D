/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:07:22 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 05:59:41 by hben-mes         ###   ########.fr       */
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
	str = ft_strtrim(map->ea_png, "\n");
	map->no = mlx_load_png(str);
	free(str);
	str = ft_strtrim(map->we_png, "\n");
	map->so = mlx_load_png(str);
	free(str);
	str = ft_strtrim(map->no_png, "\n");
	map->ea = mlx_load_png(str);
	free(str);
	str = ft_strtrim(map->so_png, "\n");
	map->we = mlx_load_png(str);
	free(str);

}