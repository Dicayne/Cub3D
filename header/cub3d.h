/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:13:04 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/07 20:39:44 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SCRWIDTH 1920
# define SCRHEIGHT 1080
# define ESC 53
# define W 13
# define S 1
# define D 2
# define A 0
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
// # include "../minilibx_mms_20191207_beta/mlx.h"
# include "../Libft/header/libft.h"

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}				t_data;
typedef struct	s_map
{
	int x;
	int y;
	int **map;
}				t_map;
typedef struct	s_path
{
	int		scrwidth;
	int		scrheight;
	char	*pars_no;
	char	*pars_so;
	char	*pars_ea;
	char	*pars_we;
	char	*pars_s;
	char	*pars_f;
	char	*pars_c;
}				t_path;

void			affimage(t_data *data, int c1, int c2, int c3, int c4);
void 			init_struct(t_path *pars, t_map *map);
int				parsing_fd(t_path *pars, t_map *map, char *fdm);
int				pars_map(t_map *map, int fd, char *str2);
void			free_struct(t_path *pars);
void			free_split(char **split);
void			print(char **split);
int				strlen_c(char *str, char c);
void			fill_8(int **map, int x, int y, int max);

#endif
