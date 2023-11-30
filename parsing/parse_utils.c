/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:09:01 by hben-mes          #+#    #+#             */
/*   Updated: 2023/11/23 12:09:01 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	player_button(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	char_hold(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1'
			&& str[i] != ' ' && !player_button(str[i]))
			return (true);
		i++;
	}
	return (false);
}

void	player_hold(char *str, int *p)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (player_button(str[i]))
			(*p)++;
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}


