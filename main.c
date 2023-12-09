
#include "cub3d.h"


int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int32_t	get_color_from_pos(mlx_texture_t *walli, int y, int x)
{
	int	index;

	if (x >= 0 && x < (int)walli->width && y >= 0 && y < (int)walli->height)
	{
		index = (walli->width * y + x) * walli->bytes_per_pixel;
		return (ft_pixel(walli->pixels[index], walli->pixels[index + 1],
				walli->pixels[index + 2], 255));
	}
	return (ft_pixel(0, 0, 0, 0));
}


// Function for finding absolute val
int abs(int n) { return ((n > 0) ? n : (n * (-1))); }

// DDA Function for line generation
// void DDA(t_map *map, int X0, int Y0, int X1, int Y1)
// {
//     // calculate dx & dy
//     int dx = X1 - X0;
//     int dy = Y1 - Y0;

//     // calculate steps required for generating pixels
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//     // calculate increment in x & y for each steps
//     float Xinc = dx / (float)steps;
//     float Yinc = dy / (float)steps;
//     // Put pixel for each step
//     float X = X0;
//     float Y = Y0;
//     int i = 0;
//     int	offse_x;
// 	int	offse_y;
//     float dist_top;

//     while (i <= steps)
//     {
//         dist_top = Y + (map->wall_height) - (HEIGHT / 2);
//         offse_y = dist_top * map->fac / 2;
//         offse_x = (int)X1 % map->no->width;
//         int color = get_color_from_pos(map->no, offse_y, offse_x);
// 	    mlx_put_pixel(map->image, offse_x, offse_y, color);
//         X += Xinc; // increment in x at each step
//         Y += Yinc; // increment in y at each step

//         i++; // Increment the loop counter
//     }
// }

/*
void DDA(mlx_image_t *image, int X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    int i = 0;
    while (i <= steps)
    {
        if ((X < WIDTH && Y < HEIGHT) && (X > 0 && Y > 0))
            mlx_put_pixel(image, X, Y, 0xFFA07Aff);
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step

        i++; // Increment the loop counter
    }
}*/

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
	if (ac != 2)
	{
		printf("Error\nTwo arguments is requirred\n");
		return (1);
	}
    args_check(av[1]);
    t_map *map = malloc(sizeof(t_map));
    map_reader(av[1], map);
    check_map(map->mapa);
    check_color(map);
    ft_position_player(map);
    get_textures(map);
    int bl = ft_init(map);
    free (map);
    return (bl);
}

