#include "../cub3d.h"

static boolean_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (i > 0 && str[i] == ' ')
		{
			if (str[i + 1] != ' ' && str[i + 1])
				return (false);
		}
		else if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	get_color(char *value)
{
	char	**rgb;
	int		i;
	int		color;
	int		c;

	i = 0;
	rgb = ft_split(value, ',', &i);
	if (!rgb)
		throw_error("Error: malloc error", g_heap());
	if (i != 2 || tab_size(rgb) != 3)
		return (free_tab(rgb), throw_error("Error: invalid color", g_heap()), 0);
	i = 0;
	color = 0;
	while (rgb[i])
	{
		if (!is_number(rgb[i]))
			return (free_tab(rgb), throw_error("Error: invalid color", g_heap()), 0);
		c = ft_atoi(rgb[i]);
		if (c < 0 || c > 255)
			return (free_tab(rgb), throw_error("Error: invalid color", g_heap()), 0);
		ft_memset(((char *)&color) + abs(i - 2), ft_atoi(rgb[i]), sizeof(char));
		i++;
	}
	return (free_tab(rgb), color);
}

void	fill_color(t_map *map, char *key, char *value)
{
	if (key && value && !ft_strcmp(key, "C"))
		map->celling_color = get_color(value);
	else if (key && value && !ft_strcmp(key, "F"))
		map->floor_color = get_color(value);
}

void	check_color(t_map *map)
{
	if (map->celling_color == -1 || map->floor_color == -1)
		throw_error("Error: invalid color", g_heap());
}
