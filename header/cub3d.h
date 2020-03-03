/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:13:04 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/03 19:45:12 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FOV 0.66
# define ESC 53
# define W 13
# define S 1
# define D 2
# define A 0
# define G 123
# define DR 124
# define MS 0.2
# define RS 0.080
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx_mms_20191207_beta/mlx.h"
# include "../Libft/header/libft.h"

typedef struct	s_print
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		y;
	int		start;
	int		color_sky;
	int		color_floor;
	double	wall_dist;
}				t_print;

typedef struct	s_speed
{
	double rot_spe;
	double mov_spe;
}				t_speed;
typedef struct	s_move
{
	int w_on;
	int s_on;
	int a_on;
	int d_on;
	int g_on;
	int dr_on;
}				t_move;
typedef struct	s_map
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;
	int		**map;
	double	pos_x;
	double	pos_y;
	char	dir;
}				t_map;
typedef struct	s_path
{
	int		scrwidth;
	int		scrheight;
	int		save;
	char	*pars_no;
	char	*pars_so;
	char	*pars_ea;
	char	*pars_we;
	char	*pars_s;
	char	*pars_f;
	char	*pars_c;
	char	*error;
}				t_path;
typedef struct	s_coor_vec
{
	double	x_f;
	double	y_f;
	int		x_i;
	int		y_i;
}				t_coor_vec;
typedef struct	s_cast
{
	t_coor_vec	dir;
	t_coor_vec	plane;
	t_coor_vec	ray_dir;
	t_coor_vec	side_dist;
	t_coor_vec	delta_dist;
	t_coor_vec	map;
	t_coor_vec	step;
	t_coor_vec	pos_tex;
	double		wall_dist;
}				t_cast;
typedef struct	s_image
{
	void	*img;
	char	*adr;
	int		*iadr;
	int		**tiadr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_h;
	int		img_w;
	double	dist;
}				t_image;
typedef struct	s_tex
{
	t_image tex_no;
	t_image tex_so;
	t_image tex_ea;
	t_image tex_we;
	t_image tex_s;
}				t_tex;
typedef struct	s_cub3d
{
	t_map	map;
	t_path	pars;
	t_cast	cast;
	t_image img;
	t_tex	tex;
	t_move	move;
	t_speed spe;
	int		bool;
}				t_cub3d;
/*
** PARSING
*/
int				parsing_fd(t_path *pars, t_map *map, char *fdm);
int				pars_map(t_map *map, int fd, char *str2, t_path *pars);
void			free_split(char **split);
int				strlen_c(char *str, char c, char d);
void			fill_8(int **map, int x, int y, int max);
void			from_0_to_8(t_map *map, int y, int x);
char			*clean_space(char **str);
int				strisnum(char *str);
int				check_map(t_map *map, t_path *pars);
int				check_closed_map(t_map *map, int y, int x);
void			init_struct_pars(t_path *pars, t_map *map);
/*
** GAME
*/
void			init_dir(t_map map, t_cast *cast);
void			init_plane(t_cast *cast);
void			init_world_color(t_cub3d *cub, int *sky, int *floor);
void			start(t_cub3d *cub);
void			init_img_struct(t_cub3d *cub);
void			my_mlx_pixel_put(t_image *img, int x, int y, int color);
void			put_mini_map(t_cub3d *cub);
void			display(t_cub3d *cub);
/*
** IMAGES
*/
void			set_images(t_cub3d *cub);
void			print_img(double wall_dist, int side, t_cub3d *cub, int x);
/*
** EVENT
*/
int				refresh(t_cub3d *cub);
void			event(t_cub3d *cub);
void			check_key_on(t_cub3d *cub);
void			init_move_ev(t_move	*move);
void			init_speed(t_speed *spe);
int				key_hook(int keycode, t_cub3d *cub);
void			move_w_s(t_cub3d *cub, int keycode);
void			move_a_d(t_cub3d *cub, int keycode);
void			rotate_g_dr(t_cub3d *cub, int keycode);
/*
** OTHER
*/
int				close_prog(t_cub3d *cub);
void			init_camera(t_cast *cast, t_path pars, int x);
void			free_struct(t_path *pars, t_map *map);
void			print_map(t_cub3d *cub);
/*
** A DEGAGER
*/
void			print(char **split);
void			print_int(t_map *coor);
#endif
