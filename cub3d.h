/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 07:01:16 by hben-mes          #+#    #+#             */
/*   Updated: 2023/12/09 10:28:32 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1512
# define HEIGHT 1512
# define SIZE_CUB 10
# define CRT_DEGRS_RADIAN M_PI

typedef struct s_garb		t_garb;
typedef struct s_texture	t_texture;
typedef struct s_mlx		t_mlx;

typedef struct s_vector
{
	float					x;
	float					y;
}							t_vector;

typedef struct s_ver_horizon
{
	float					d_vertical;
	float					d_horizontal;
	t_vector				ray_vertic;
	t_vector				ray_horizon;
}							t_ver_horizon;

typedef struct s_garb
{
	void					*addr;
	t_garb					*nxt;
	t_garb					*lst;
}							t_garb;

typedef struct s_mlx
{
	void					*mlx_ptr;
	void					*win_ptr;
}							t_mlx;

typedef struct s_texture
{
	char					*val;
	char					*cue;
	t_texture				*nxt;
	t_texture				*lst;
}							t_texture;

typedef struct s_map
{
	mlx_image_t				*image;
	mlx_image_t				*image_map;
	t_texture				*textures;
	void					*mlx_ptr;
	int						color_c;
	int						color_f;
	mlx_texture_t			*no;
	mlx_texture_t			*so;
	mlx_texture_t			*ea;
	mlx_texture_t			*we;
	int						r;
	int						g;
	int						b;
	int						r1;
	int						g1;
	int						b1;
	char					*no_png;
	char					*so_png;
	char					*ea_png;
	char					*we_png;
	float					fac;
	float					dist_top;
	char					**mapa;
	float					wall_height;
	float					wall_width;
	float					x_p;
	float					y_p;
	float					ray_p_x;
	float					ray_p_y;
	char					directin;
	int						width;
	int						height;
	int						color;
	mlx_t					*mlx;
	float					p_rotation;
	float					destonation;
	int						size_x;
	int						size_y;
	t_vector				ray;
}							t_map;

enum						e_keys
{
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125
};

/// functions init ////
int							ft_init(t_map *map);
int							ft_mini_init(t_map *map);
/// functions raycasting ////
void						ft_start_raycasting(t_map *map);
t_vector					ft_ray_casting_vertical(t_map *map, float dd);
t_vector					ft_ray_casting_horizontal(t_map *map, float dd);
t_vector					ft_ray_casting(t_map *map, float dd);
// void DDA(t_map *map, int X0, int Y0, int X1, int Y1);
// void						DDA(mlx_image_t *image, int X0, int Y0, int X1,
// 								int Y1);
/// functions movement ////
void						ft_movemnt(t_map *map);
void						ft_w(t_map *map);
void						ft_s(t_map *map);
void						ft_a(t_map *map);
void						ft_d(t_map *map);

/// functions draw ////
void						ft_mini_draw(t_map *map, int x, int y);
void						ft_draw_cub1(t_map *map, int hei, int color);
void						ft_draw_cub(mlx_image_t *map, int x_start,
								int y_start, int color);
// void ft_first_draw(t_map *map);
void						ft_draw(t_map *map);
void						ft_draw_wall(t_map *map, float ray_nb);
void						ft_first_draw(mlx_image_t *image);

t_vector					ft_util(t_map *map, t_ver_horizon ver_horizon);
/// functions position player ////
void						ft_position_player(t_map *map);
void						ft_n_p(t_map *map, int x, int y);
void						ft_s_p(t_map *map, int x, int y);
void						ft_e_p(t_map *map, int x, int y);
void						ft_w_p(t_map *map, int x, int y);

void						put_textures(t_map *map, mlx_texture_t *x,
								float ray_nb);
void						put_color_sky(t_map *map);
int							ft_pixel(int r, int g, int b, int a);
void						get_textures(t_map *var);
//parsing
int							ft_num(char *s);
int							ft_error(char **rgb, int i);
void						ft_put_rgb(t_map *map, char **rgb);
void						ft_put_rgb1(t_map *map, char **rgb);
int							color_put(char *val, t_map *map);
int							color_put1(char *val, t_map *map);
void						color_load(t_map *map, char *cue, char *val);
void						check_color(t_map *map);
void						check_map(char **map);
void						text_fill(t_map *map, char *cue, char *val);
void						check_textures(t_map *map);
int							player_button(char c);
int							char_hold(char *s);
void						player_hold(char *s, int *j);
int							ft_strcmp(char *s1, char *s2);
int							tab_tab(char **tab);
void						free_size(char **tab);
char						*join_free(char *s1, char *s2);
void						args_check(char *p);
void						error_script(char *scr, t_garb **top);
t_garb						**s_top(void);
void						garbage_join(t_garb **top, void *addr);
void						empty_garbage(t_garb **top);
void						texture_parse(char *l, t_map *map);
void						map_reader(char *p, t_map *map);
#endif
