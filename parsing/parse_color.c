/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:08:44 by hben-mes          #+#    #+#             */
/*   Updated: 2023/11/23 12:08:44 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_num  (char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (i > 0 && str[i] == ' ')
		{
			if (str[i + 1] != ' ' && str[i + 1])
				return (false);
		}
		else if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	color_put(char *value)
{
	char	**rgb;
	int		i;
	int		color;
	int		c;

	i = 0;
	rgb = ft_split(value, ',');
	if (!rgb)
		error_script("Error: malloc error", s_top());
	// if (i != 2 || tab_tab(rgb) != 3)
	// free_size(rgb);
	// error_script("Error: invalid color 1", s_top());
	i = 0;
	color = 0;
	while (rgb[i])
	{
		if (!ft_num  (rgb[i]))
			return (free_size(rgb), error_script("Error: invalid color", s_top()), 0);
		c = ft_atoi(rgb[i]);
		if (c < 0 || c > 255)
			return (free_size(rgb), error_script("Error: invalid color", s_top()), 0);
		ft_memset(((char *)&color) + abs(i - 2), ft_atoi(rgb[i]), sizeof(char));
		i++;
	}
	return (free_size(rgb), color);
}

void	color_load(t_map *map, char *key, char *value)
{
	if (key && value && !ft_strcmp(key, "C"))
		map->celling_color = color_put(value);
	else if (key && value && !ft_strcmp(key, "F"))
		map->floor_color = color_put(value);
}

void	check_color(t_map *map)
{
	if (map->celling_color == -1 || map->floor_color == -1)
		error_script("Error: invalid color", s_top());
}
