/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:08:44 by hben-mes          #+#    #+#             */
/*   Updated: 2023/12/09 06:57:57 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_num(char *s)
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

void	color_load(t_map *map, char *cue, char *val)
{
	if (cue && val && !ft_strcmp(val, "C"))
		map->color_c = color_put(cue, map);
	else if (cue && val && !ft_strcmp(val, "F"))
		map->color_f = color_put1(cue, map);
}

void	check_color(t_map *map)
{
	if (map->color_c == -1 || map->color_f == -1)
		error_script("Error: color_is_invalid", s_top());
}
