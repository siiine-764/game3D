#include "../cub3d.h"

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

bool	contains_bad_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1'
			&& str[i] != ' ' && !is_player(str[i]))
			return (true);
		i++;
	}
	return (false);
}

void	contains_player(char *str, int *p)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_player(str[i]))
			(*p)++;
		i++;
	}
}


