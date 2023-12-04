/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:09:16 by hben-mes          #+#    #+#             */
/*   Updated: 2023/11/23 12:09:16 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	texture_parse(char *line, t_map *map)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	key = ft_substr(line, 0, i);
	garbage_join(s_top(), key);
	if (key && (ft_strcmp(key, "NO") && ft_strcmp(key, "SO")
			&& ft_strcmp(key, "EA") && ft_strcmp(key, "WE")
			&& ft_strcmp(key, "C") && ft_strcmp(key, "F")))
					error_script("Error: texture_error 0", s_top());
	while (line[i] && line[i] == ' ')
		i++;
	value = ft_substr(line, i, ft_strlen(line) - i - 1);
	if (!key || !value)
		error_script("Error: malloc_error", s_top());
	garbage_join(s_top(), value);
	text_fill(map, key, value);
	color_load(map, key, value);
}

static void	line_parsing(char *line, int index, t_map *map, char **joined)
{
	static bool	flag;

	if (index < 6)
		texture_parse(line, map);
	else
	{
		if (line[0] != '\n')
			flag = true;
		if (flag && line[0] == '\n')
		{
			free(*joined);
			error_script("Error: map_empty_line", s_top());
		}
		*joined = join_free(*joined, line);
	}
}

static void	assist_map_reader(t_map *map, int fd, char *joined)
{
	int	i;

	i = 0; 
	close(fd);
	map->mapa = ft_split(joined, '\n');
	free(joined);
	if (!map->mapa || !map->mapa[0])
		error_script("Error: map is empty", s_top());
	while (map->mapa[i])
		garbage_join(s_top(), map->mapa[i++]);
	garbage_join(s_top(), map->mapa);
}

void	map_reader(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	char	*joined;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_script("Error: file_error", NULL);
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
		line_parsing(line, i, map, &joined);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	assist_map_reader(map, fd, joined);
}
