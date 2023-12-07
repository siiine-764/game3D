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

int	check_top_bottom(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	ft_close(char *s)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(s);
	while (s[i])
	{
		if (i == 0 && s[i] != '1' && s[i] != ' ')
			return (false);
		else if (i == l - 1 && s[i] != '1' && s[i] != ' ')
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
					error_script("Error: error_in_closing_map", s_top());
			if (i > 0 && i < tab_tab(map) - 1
				&& (map[i][j] == '0' || player_button(map[i][j])))
				if ((j >= (int)ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
				|| (j >= (int)ft_strlen(map[i + 1]) || map[i + 1][j] == ' '))
					error_script("Error: error_in_closing_map", s_top());
			j++;
		}
		i++;
	}
}

void	 check_map(char **map)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = tab_tab(map);
	while (map[i])
	{
		if ((i == 0 || i == size - 1) && !check_top_bottom(map[i]))
			error_script("Error: error_in_closing_map", s_top());
		else if (i != 0 && i != size - 1 && !ft_close(map[i]))
			error_script("Error: error_in_closing_map", s_top());
		if (char_hold(map[i]))
			error_script("Error: invalid_char", s_top());
		player_hold(map[i], &j);
		i++;
	}
	if (j != 1)
		error_script("Error: error_in_player", s_top());
	check_space(map);
}