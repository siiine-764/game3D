/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:09:16 by hben-mes          #+#    #+#             */
/*   Updated: 2023/11/23 12:09:16 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_texture_rgb(char *line, t_map *map)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	key = ft_substr(line, 0, i);
	add_to_garbage(g_heap(), key);
	if (key && (ft_strcmp(key, "NO") && ft_strcmp(key, "SO")
			&& ft_strcmp(key, "EA") && ft_strcmp(key, "WE")
			&& ft_strcmp(key, "C") && ft_strcmp(key, "F")))
		throw_error("Error: texture_error", g_heap());
	while (line[i] && line[i] == ' ')
		i++;
	value = ft_substr(line, i, ft_strlen(line) - i - 1);
	if (!key || !value)
		throw_error("Error: malloc_error", g_heap());
	add_to_garbage(g_heap(), value);
	fill_tetxures_list(map, key, value);
	fill_color(map, key, value);
}

void	parse_line(char *line, int index, t_map *map, char **joined)
{
	static bool	flag;

	if (index < 6)
		parse_texture_rgb(line, map);
	else
	{
		if (line[0] != '\n')
			flag = true;
		if (flag && line[0] == '\n')
		{
			free(*joined);
			throw_error("Error: map_empty_line", g_heap());
		}
		*joined = free_s1_join(*joined, line);
	}
}

void	read_map_helper(t_map *map, int fd, char *joined)
{
	int	i;

	i = 0;
	close(fd);
	map->mapa = ft_split(joined, '\n');
	free(joined);
	if (!map->mapa || !map->mapa[0])
		throw_error("Error: map is empty", g_heap());
	while (map->mapa[i])
		add_to_garbage(g_heap(), map->mapa[i++]);
	add_to_garbage(g_heap(), map->mapa);
}

void	read_map(char *path, t_map *mapa)
{
	int		fd;
	int		i;
	char	*line;
	char	*joined;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		throw_error("Error: file_error", NULL);
	i = 0;
	joined = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (i < 6 && *line == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		parse_line(line, i, mapa, &joined);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	read_map_helper(mapa, fd, joined);
}
