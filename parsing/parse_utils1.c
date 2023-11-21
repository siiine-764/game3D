#include "../cub3d.h"

int	tab_size(char **tab)
{
	int	i;

	if (!tab || !*tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

char	*free_s1_join(char *s1, char *s2)
{
	char	*joined;

	if (!s1)
		s1 = ft_strdup("");
	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}