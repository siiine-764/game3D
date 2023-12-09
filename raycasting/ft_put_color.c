
#include "../cub3d.h"

int	ft_pxl(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	put_color_sky(t_map *map)
{
	int	color;
	int	i;

	i = 0;
	color = 0;
	while (color < HEIGHT / 2)
	{
		i = 0;
		while (i <= WIDTH)
		{
			mlx_put_pixel(map->image, i++, color, ft_pxl(map->r, map->g, map->b,
					255));
		}
		color++;
	}
	while (color < HEIGHT)
	{
		i = 0;
		while (i <= WIDTH)
		{
			mlx_put_pixel(map->image, i++, color, ft_pxl(map->r1, map->g1,
					map->b1, 255));
		}
		color++;
	}
}
