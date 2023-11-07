/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:33:40 by mayache-          #+#    #+#             */
/*   Updated: 2023/11/07 17:33:46 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_clean(char *buff)
{
	char	*vagabond;
	int		len;
	int		molphy;

	molphy = 0;
	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (!buff[len] || (buff[len] == '\n' && buff[len + 1] == '\0'))
	{
		free(buff);
		return (NULL);
	}
	vagabond = (char *)malloc(str_len(buff) - len);
	if (!vagabond)
		return (NULL);
	len++;
	while (buff[len])
		vagabond[molphy++] = buff[len++];
	vagabond[molphy] = '\0';
	free(buff);
	return (vagabond);
}

char	*get_next_line(int fd)
{
	char		*tento;
	static char	*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_spanen_lessen(buffer, fd);
	if (!buffer)
		return (NULL);
	tento = ft_lessen(buffer);
	buffer = ft_clean(buffer);
	return (tento);
}
