/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:09:06 by hben-mes          #+#    #+#             */
/*   Updated: 2023/11/23 12:09:06 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	tab_tab(char **tab)
{
	int	i;

	if (!tab || !*tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

char	*join_free(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

void	args_check(char *p)
{
	char	*s;

	s = ft_strchr(p, '.');
	if (!s)
		error_script("Error: invalid_args", NULL);
	if (ft_strcmp(s, ".cub"))
		error_script("Error: invalid_args", NULL);
}
