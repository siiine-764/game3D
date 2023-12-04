/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:18:53 by hben-mes          #+#    #+#             */
/*   Updated: 2023/12/04 12:49:58 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function for finding absolute value
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
    //// parsing ////
    t_map *map = malloc(sizeof(t_map));
    map_reader(av[1], map);
    // FILE *file;
    // map->double_array_map = malloc(100 * sizeof(char *));
    // file = fopen("./map/path", "r");
    // if (file == NULL)
    // {
    //     printf("Unable to open the file.\n");
    //     return 1;
    // }
    // char buffer[100];
    // int i = 0;
    // while (fgets(buffer, sizeof(buffer), file) != NULL)
    // {
    //     map->double_array_map[i] = strdup((const char *)buffer);
    //     i++;
    // }
    // map->double_array_map[i] = NULL;
    /// end parsing ////
    ft_position_player(map);
    int bl = ft_init(map);
    // fclose(file);
    return (bl);
}
