#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
#include <string.h>

#define WIDTH 1512
#define HEIGHT 1512
#define SIZE_CUB 10

typedef struct s_map
{
    mlx_image_t* image;
    char **double_array_map;
    float x_p;
    float y_p;
    int width;
    int height;
    int color;
    mlx_t* mlx;
} t_map;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_draw_cub(t_map* map, int width, int height, int x_start, int y_start, int color)
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


void ft_hook(void* param)
{
	t_map* map = param;

    (void)map;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->y_p -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->y_p += 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->x_p -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->x_p += 5;
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
        y++;
    }

    ft_draw_cub(map, SIZE_CUB, SIZE_CUB, map->x_p, map->y_p, 0xff0000ff);
}

// -----------------------------------------------------------------------------

int32_t main(int ac, char** av)
{

    (void)ac;
    (void)av;
	t_map *map = malloc(sizeof(t_map));
    

    // Declare a file pointer
        FILE *file;
    // array to store the read line
    map->double_array_map = malloc(100 * sizeof(char*));

        // Open the file for reading
        file = fopen("./path", "r");
            // Check if the file was opened successfully
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1; // Return an error code
    }

        // Read and print the contents of the file
    char buffer[100]; // Create a buffer to store the read data
    int i = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
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
            ///checx player N
            printf("%c", map->double_array_map[y][x]);
            if (map->double_array_map[y][x] == 'N')
            {
                map->x_p = x * SIZE_CUB;
                map->y_p = y * SIZE_CUB;
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
		return(EXIT_FAILURE);
	}
	if (!(map->image = mlx_new_image(map->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(map->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(map->mlx, map->image, 0, 0) == -1)
	{
		mlx_close_window(map->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	// mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(map->mlx, ft_hook, map);

	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);

    // Close the file
    fclose(file);
	return (EXIT_SUCCESS);
}
