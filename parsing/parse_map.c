/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:08:51 by hben-mes          #+#    #+#             */
/*   Updated: 2023/11/23 12:08:51 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	top_bottom_closed(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	is_closed(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (i == 0 && str[i] != '1' && str[i] != ' ')
			return (false);
		else if (i == len - 1 && str[i] != '1' && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	space_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (j > 0 && j < (int)ft_strlen(map[i]) - 1
				&& (map[i][j] == '0' || is_player(map[i][j])))
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					throw_error("Error: map_not_closed", g_heap());
			if (i > 0 && i < tab_size(map) - 1
				&& (map[i][j] == '0' || is_player(map[i][j])))
				if ((j >= (int)ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
				|| (j >= (int)ft_strlen(map[i + 1]) || map[i + 1][j] == ' '))
					throw_error("Error: map_not_closed", g_heap());
			j++;
		}
		i++;
	}
}

void	map_checker(char **map)
{
	int	i;
	int	p;
	int	map_size;

	i = 0;
	p = 0;
	map_size = tab_size(map);
	while (map[i])
	{
		if ((i == 0 || i == map_size - 1) && !top_bottom_closed(map[i]))
			throw_error("Error: map_not_closed", g_heap());
		else if (i != 0 && i != map_size - 1 && !is_closed(map[i]))
			throw_error("Error: map_not_closed", g_heap());
		if (contains_bad_char(map[i]))
			throw_error("Error: bad_char", g_heap());
		contains_player(map[i], &p);
		i++;
	}
	if (p != 1)
		throw_error("Error: player_error", g_heap());
	space_checker(map);
}