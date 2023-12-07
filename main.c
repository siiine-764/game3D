/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:06:42 by hben-mes          #+#    #+#             */
/*   Updated: 2023/12/07 13:21:07 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function for finding absolute val
int abs(int n) { return ((n > 0) ? n : (n * (-1))); }

// DDA Function for line generation
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
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
	if (ac != 2)
	{
		printf("Error\nTwo arguments is requirred\n");
		return (1);
	}
    t_map *map = malloc(sizeof(t_map));
    map_reader(av[1], map);
    text_fill(map, av[1], av[1]);
    ft_position_player(map);
    int bl = ft_init(map);
    free (map);
    return (bl);
}
