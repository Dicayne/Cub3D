/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:13:04 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/15 16:25:46 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FOV (66 * 3.14159265) / 180
# define ESC 53
# define W 13
# define S 1
# define D 2
# define A 0
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../minilibx_mms_20191207_beta/mlx.h"
# include "../Libft/header/libft.h"

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}				t_data;
typedef struct	s_map
{
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
	t_coor_vec dir;
	t_coor_vec plane;
	t_coor_vec ray_dir;
	t_coor_vec side_dist;
	t_coor_vec delta_dist;
	t_coor_vec map;
	t_coor_vec step;
}				t_cast;
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
/*
** GAME
*/
void			init_dir(t_map *map,t_cast *cast);
void			init_plane(t_cast *cast);
void			start(t_path pars, t_map *map, t_data *data);
/*
** OTHER
*/
void			init_struct(t_path *pars, t_map *map);
void			init_camera(t_cast *cast, t_path pars, int x);
void			affimage(t_data *data, int c1, int c2, int c3, int c4);
void			free_struct(t_path *pars, t_map *map);
void			print_map(t_map *map, t_path pars, t_data *data);
//int 			key_hook(int keycode, t_data *param, t_map *map, t_path pars);
//void			toto(t_map map, t_path pars, t_data *data);
/*
** A DEGAGER
*/
void			print(char **split);
void			print_int(t_map *coor);
#endif
