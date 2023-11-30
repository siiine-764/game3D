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

int	check_top_bottom(char *str)
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

int	ft_close(char *str)
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

void	check_space(char **map)
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
				&& (map[i][j] == '0' || player_button(map[i][j])))
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					error_script("Error: map_not_closed", s_top());
			if (i > 0 && i < tab_tab(map) - 1
				&& (map[i][j] == '0' || player_button(map[i][j])))
				if ((j >= (int)ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
				|| (j >= (int)ft_strlen(map[i + 1]) || map[i + 1][j] == ' '))
					error_script("Error: map_not_closed", s_top());
			j++;
		}
		i++;
	}
}

void	check_map(char **map)
{
	int	i;
	int	p;
	int	map_size;

	i = 0;
	p = 0;
	map_size = tab_tab(map);
	while (map[i])
	{
		if ((i == 0 || i == map_size - 1) && !check_top_bottom(map[i]))
			error_script("Error: map_not_closed", s_top());
		else if (i != 0 && i != map_size - 1 && !ft_close(map[i]))
			error_script("Error: map_not_closed", s_top());
		if (char_hold(map[i]))
			error_script("Error: bad_char", s_top());
		player_hold(map[i], &p);
		i++;
	}
	if (p != 1)
		error_script("Error: player_error", s_top());
	check_space(map);
}