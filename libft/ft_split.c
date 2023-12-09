/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:27:45 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 02:56:21 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt(char const *s, char dim, int *counter)
{
	size_t	l;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	l = ft_strlen(s);
	while (i < l)
	{
		while (s[i] == dim)
		{
			i++;
			if (counter)
				(*counter)++;
		}
		if (s[i] != dim && s[i] != '\0')
			c++;
		while (s[i] != dim && s[i] != '\0')
			i++;
	}
	return (c);
}

static char	**free_func(char **p, size_t i)
{
	size_t	k;

	k = 0;
	while (k < i)
	{
		free(p[k]);
		p[k] = NULL;
		k++;
	}
	free(p);
	p = NULL;
	return (NULL);
}

static char	**load_func(char const *str, char c, char **s, size_t cnt)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (i < cnt)
	{
		while (str[start] == c && str[start] != '\0')
			start++;
		end = start;
		while (str[end] != c && str[end] != '\0')
			end++;
		s[i] = ft_substr(str, start, end - start);
		if (s[i] == NULL)
			return (free_func(s, i));
		start = end;
		i++;
	}
	s[i] = NULL;
	return (s);
}

char	**ft_split(char const *str, char c, int *counter)
{
	size_t	cnt;
	char	**s;
	
	if (str == NULL)
		return (NULL);
	cnt = ft_cnt(str, c, counter);
	s = (char **)malloc((cnt + 1) * sizeof(char *));
	if (s == NULL)
		return (NULL);
	return (load_func(str, c, s, cnt));
}

