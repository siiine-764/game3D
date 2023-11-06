/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:29:12 by mayache-          #+#    #+#             */
/*   Updated: 2023/11/06 16:15:00 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// Function for finding absolute value
int abs(int n) { return ((n > 0) ? n : (n * (-1))); }

// DDA Function for line generation
void DDA(t_map *map, int X0, int Y0, int X1, int Y1)
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
            mlx_put_pixel(map->image, X, Y, 0xFFA07Aff);
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step

        i++; // Increment the loop counter
    }
}

// void ft_line(t_map* map, int x_point_end, int y_point_end)
// {
//     int x = map->x_p;
//     int y = map->y_p;
//     int d_x = x_point_end - x;
//     int d_y = y_point_end - y;
//     while (y < 60)
//     {
//             mlx_put_pixel(map->image, x, y, 0xFFA07Aff);
//         y++;
//     }
// }
void ft_draw_cub(t_map *map, int width, int height, int x_start, int y_start, int color)
{
    (void)map;
    int i = x_start;
    while (i < (int)(x_start + width))
    {
        int y = y_start;
        while (y < (int)(y_start + height))
        {
            if (y < HEIGHT && i < WIDTH && y > 0 && i > 0)
                mlx_put_pixel(map->image, i, y, color);
            y++;
        }
        i++;
    }
}

void ft_hook(void *param)
{
    t_map *map = param;
    (void)map;
    if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(map->mlx);
    // if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
    // 	map->y_p -= map->p_rotation;
    // if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
    // 	map->y_p += map->p_rotation;
    if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
        map->p_rotation -= 1;
    if (map->p_rotation > 360)
        map->p_rotation -= 360;
    if (map->p_rotation < 0)
        map->p_rotation += 360;
    if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
        map->p_rotation += 1;
    //// player rotation
    if (mlx_is_key_down(map->mlx, MLX_KEY_W))
    {
        map->y_p += sin(map->p_rotation * convert_degrees_radian);
        map->x_p += cos(map->p_rotation * convert_degrees_radian);
        if (map->double_array_map[(int)(map->y_p / SIZE_CUB)][(int)(map->x_p / SIZE_CUB)] == '1')
        {
            map->y_p -= sin(map->p_rotation * convert_degrees_radian);
            map->x_p -= cos(map->p_rotation * convert_degrees_radian);
        }
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_S))
    {
        map->y_p -= sin(map->p_rotation * convert_degrees_radian);
        map->x_p -= cos(map->p_rotation * convert_degrees_radian);
        if (map->double_array_map[(int)(map->y_p / SIZE_CUB)][(int)(map->x_p / SIZE_CUB)] == '1')
        {
            map->y_p += sin(map->p_rotation * convert_degrees_radian);
            map->x_p += cos(map->p_rotation * convert_degrees_radian);
        }
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_A))
    {
        map->y_p -= cos(map->p_rotation * convert_degrees_radian);
        map->x_p += sin(map->p_rotation * convert_degrees_radian);
        if (map->double_array_map[(int)(map->y_p / SIZE_CUB)][(int)(map->x_p / SIZE_CUB)] == '1')
        {
            map->y_p += cos(map->p_rotation * convert_degrees_radian);
            map->x_p -= sin(map->p_rotation * convert_degrees_radian);
        }
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_D))
    {
        map->y_p += cos(map->p_rotation * convert_degrees_radian);
        map->x_p -= sin(map->p_rotation * convert_degrees_radian);
        if (map->double_array_map[(int)(map->y_p / SIZE_CUB)][(int)(map->x_p / SIZE_CUB)] == '1')
        {
            map->y_p -= cos(map->p_rotation * convert_degrees_radian);
            map->x_p += sin(map->p_rotation * convert_degrees_radian);
        }
    }
    // printf("x_p = %f, y_p = %f\n", map->x_p, map->y_p);
    // printf("p_rotation = %f\n", map->p_rotation);
    // if (mlx_is_key_down(map->mlx, MLX_KEY_A))
    //     map->x_p -= map->p_rotation;
    // if (mlx_is_key_down(map->mlx, MLX_KEY_D))
    //     map->x_p += map->p_rotation;
    int x = 0;
    int y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            mlx_put_pixel(map->image, x, y, 0x00000000);
            x++;
        }
        y++;
    }

    x = 0;
    y = 0;
    int max = 0;
    while (map->double_array_map[y] != NULL)
    {
        x = 0;
        while (map->double_array_map[y][x] != '\0')
        {
            if (map->double_array_map[y][x] == '1')
                ft_draw_cub(map, SIZE_CUB, SIZE_CUB, x * SIZE_CUB, y * SIZE_CUB, 0x800080ff);

            if (map->double_array_map[y][x] == '0')
                ft_draw_cub(map, SIZE_CUB, SIZE_CUB, x * SIZE_CUB, y * SIZE_CUB, 0xffffffff);
            x++;
        }
        if (max < x)
            max = x;
        y++;
    }

    map->size_x = max;
    map->size_y = y;
    ft_draw_cub(map, 5, 5, map->x_p, map->y_p, 0xff0000ff);
    // ft_line(map, map->x_p + 100, map->y_p + 100);
    // DDA(map, map->x_p, map->y_p, map->x_p + cos(map->p_rotation * convert_degrees_radian) * 100,
    //      map->y_p + sin(map->p_rotation * convert_degrees_radian) * 100);
    float dd = map->p_rotation - 30;
    float ray_nb = 0;
    t_vector ray;

    while (ray_nb < WIDTH)
    {
        if (dd > 360)
            dd -= 360;
        if (dd < 0)
            dd += 360;
        ray = ft_ray_casting(map, dd);
        // printf("ray hook : ray.x = %f, ray.y = %f\n", ray.x, ray.y);
        DDA(map, map->x_p, map->y_p, ray.x, ray.y);
        map->destonation = map->destonation * cos((dd - map->p_rotation) * (M_PI / 180.0));
        ft_draw_wall(map, ray_nb);
        // DDA(map, map->x_p, map->y_p, map->x_p + cos((map->p_rotation + dd) * convert_degrees_radian) * 100,
        //     map->y_p + sin((map->p_rotation + dd) * convert_degrees_radian) * 100);
        ray_nb++;
        dd += (60.0 / WIDTH);
    }
}

// -----------------------------------------------------------------------------

int32_t main(int ac, char **av)
{

    (void)ac;
    (void)av;
    t_map *map = malloc(sizeof(t_map));

    // Declare a file pointer
    FILE *file;
    // array to store the read line
    map->double_array_map = malloc(100 * sizeof(char *));

    // Open the file for reading
    file = fopen("./map/path", "r");
    // Check if the file was opened successfully
    if (file == NULL)
    {
        printf("Unable to open the file.\n");
        return 1; // Return an error code
    }

    // Read and print the contents of the file
    char buffer[100]; // Create a buffer to store the read data
    int i = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        map->double_array_map[i] = strdup((const char *)buffer);
        // printf("%s", double_array_map[i]);
        i++;
    }
    map->double_array_map[i] = NULL;

    int y = 0;
    int x = 0;
    // int x_p = 0;
    // int y_p = 0;
    while (map->double_array_map[y])
    {
        x = 0;
        while (map->double_array_map[y][x] != '\0')
        {
            /// checx player N
            // printf("%c", map->double_array_map[y][x]);
            if (map->double_array_map[y][x] == 'N')
            {
                map->x_p = x * SIZE_CUB;
                map->y_p = y * SIZE_CUB;
                map->p_rotation = 270;
                // printf("player N found at %f, %f\n", map->x_p, map->y_p);
            }
            else if (map->double_array_map[y][x] == 'S')
            {
                map->x_p = x * SIZE_CUB;
                map->y_p = y * SIZE_CUB;
                map->p_rotation = 90;
                // printf("player N found at %f, %f\n", map->x_p, map->y_p);
            }
            else if (map->double_array_map[y][x] == 'E')
            {
                map->x_p = x * SIZE_CUB;
                map->y_p = y * SIZE_CUB;
                map->p_rotation = 0;
                // printf("player N found at %f, %f\n", map->x_p, map->y_p);
            }
            else if (map->double_array_map[y][x] == 'W')
            {
                map->x_p = x * SIZE_CUB;
                map->y_p = y * SIZE_CUB;
                map->p_rotation = 180;
                // printf("player N found at %f, %f\n", map->x_p, map->y_p);
            }
            // printf("%c", double_array_map[y][x]);
            x++;
        }
        y++;
    }

    // Gotta error check this stuff
    if (!(map->mlx = mlx_init(WIDTH, HEIGHT, "GAME 3D", true)))
    {
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    if (!(map->image = mlx_new_image(map->mlx, WIDTH, HEIGHT)))
    {
        mlx_close_window(map->mlx);
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    if (mlx_image_to_window(map->mlx, map->image, 0, 0) == -1)
    {
        mlx_close_window(map->mlx);
        puts(mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
    // mlx_loop_hook(mlx, ft_randomize, mlx);
    mlx_loop_hook(map->mlx, ft_hook, map);

    mlx_loop(map->mlx);
    mlx_terminate(map->mlx);

    // Close the file
    fclose(file);
    return (EXIT_SUCCESS);
}
