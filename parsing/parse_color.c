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

int ft_num  (char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (false);
	while (s[i] && s[i] == ' ')
		i++;
	if (!s[i])
		return (false);
	while (s[i])
	{
		if (i > 0 && s[i] == ' ')
		{
			if (s[i + 1] != ' ' && s[i + 1])
				return (false);
		}
		else if (!ft_isdigit(s[i]) && s[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	color_put(char *val)
{
	int		i;
	int		col;
	int		num;
	char	**rgb;

	i = 0;
	rgb = ft_split(val, ',', &i);
	if (!rgb)
		error_script("Error: error_in_malloc", s_top());
	if (i != 2 || tab_tab(rgb) != 3)
	return (free_size(rgb), error_script("Error: color_is_invalid", s_top()), 0);
	i = 0;
	col = 0;
	while (rgb[i])
	{
		if (!ft_num  (rgb[i]))
			return (free_size(rgb), error_script("Error: color_is_invalid", s_top()), 0);
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			return (free_size(rgb), error_script("Error: color_is_invalid", s_top()), 0);
		ft_memset(((char *)&col) + abs(i - 2), ft_atoi(rgb[i]), sizeof(char));
		i++;
	}
	return (free_size(rgb), col);
}

void	color_load(t_map *map, char *cue, char *val)
{
	if (cue && val && !ft_strcmp(cue, "C"))
		map->color_c = color_put(val);
	else if (cue && val && !ft_strcmp(cue, "F"))
		map->color_f = color_put(val);
}

void	check_color(t_map *map)
{
	if (map->color_c == -1 || map->color_f == -1)
		error_script("Error: color_is_invalid", s_top());
}
