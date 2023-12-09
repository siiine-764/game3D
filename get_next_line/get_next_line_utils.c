/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:34:11 by mayache-          #+#    #+#             */
/*   Updated: 2023/12/09 06:35:15 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_len(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*str_chr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*str_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = 0;
	str = (char *)malloc(str_len(s2) + str_len(s1) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_lessen(char *buff)
{
	char	*block;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[len] && buff[len] != '\n')
		len++;
	block = (char *)malloc((len + 2) * sizeof('\0'));
	if (!block)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
	{
		block[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		block[i] = '\n';
		i++;
	}
	block[i] = '\0';
	return (block);
}

char	*ft_spanen_lessen(char *utopia, int fd)
{
	int		due;
	char	*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	due = 1;
	while (!str_chr(utopia, '\n') && due != 0)
	{
		due = read(fd, buff, BUFFER_SIZE);
		if (due == -1)
		{
			free(utopia);
			free(buff);
			return (NULL);
		}
		buff[due] = '\0';
		utopia = str_join(utopia, buff);
	}
	free(buff);
	return (utopia);
}
