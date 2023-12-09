/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 06:49:37 by hben-mes          #+#    #+#             */
/*   Updated: 2023/12/09 06:57:01 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_rgb(t_map *map, char **rgb)
{
	map->r = ft_atoi(rgb[0]);
	map->g = ft_atoi(rgb[1]);
	map->b = ft_atoi(rgb[2]);
}

void	ft_put_rgb1(t_map *map, char **rgb)
{
	map->r1 = ft_atoi(rgb[0]);
	map->g1 = ft_atoi(rgb[1]);
	map->b1 = ft_atoi(rgb[2]);
}

int	ft_error(char **rgb, int i)
{
	if (!rgb)
	{
		error_script("Error: error_in_malloc", s_top());
		return (0);
	}
	if (i != 2 || tab_tab(rgb) != 3)
		return (free_size(rgb), 
			error_script("Error: color_is_invalid", s_top()), 0);
	return (0);
}

int	color_put(char *val, t_map *map)
{
	int		i;
	int		col;
	int		num;
	char	**rgb;

	i = 0;
	rgb = ft_split(val, ',', &i);
	ft_put_rgb(map, rgb);
	ft_error(rgb, i);
	i = 0;
	col = 0;
	while (rgb[i])
	{
		if (!ft_num(rgb[i]))
			return (free_size(rgb), error_script("Error: color_is_invalid",
					s_top()), 0);
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			return (free_size(rgb), error_script("Error: color_is_invalid",
					s_top()), 0);
		ft_memset(((char *)&col) + abs(i - 2), ft_atoi(rgb[i]), sizeof(char));
		i++;
	}
	return (free_size(rgb), col);
}

int	color_put1(char *val, t_map *map)
{
	int		i;
	int		col;
	int		num;
	char	**rgb;

	i = 0;
	rgb = ft_split(val, ',', &i);
	ft_put_rgb1(map, rgb);
	ft_error(rgb, i);
	i = 0;
	col = 0;
	while (rgb[i])
	{
		if (!ft_num(rgb[i]))
			return (free_size(rgb), error_script("Error: color_is_invalid",
					s_top()), 0);
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			return (free_size(rgb), error_script("Error: color_is_invalid",
					s_top()), 0);
		ft_memset(((char *)&col) + abs(i - 2), ft_atoi(rgb[i]), sizeof(char));
		i++;
	}
	return (free_size(rgb), col);
}
