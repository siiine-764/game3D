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

int	player_button(char n)
{
	return (n == 'N' || n == 'S' || n == 'E' || n == 'W');
}

int	char_hold(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != ' ' && !player_button(s[i]))
			return (true);
		i++;
	}
	return (false);
}

void	player_hold(char *s, int *k)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (player_button(s[i]))
			(*k)++;
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
