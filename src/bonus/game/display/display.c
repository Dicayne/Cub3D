/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:34:12 by vmoreau           #+#    #+#             */
/*   Updated: 2020/05/27 18:39:59 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

int			darkness_mode(int color, double wall_dist)
{
	int		r;
	int		g;
	int		b;
	double	per;

	r = 0xff0000 & color;
	g = 0xff00 & color;
	b = 0xff & color;
	per = 1.0f - wall_dist / 12;
	if (per < 0.0f)
		per = 0.0f;
	else if (per > 1.0f)
		per = 1.0f;
	r = ((int)((double)0x0 + (r - 0x0) * per) & 0xFF0000);
	g = ((int)((double)0x0 + (g - 0x0) * per) & 0xFF00);
	b = ((int)((double)0x0 + (b - 0x0) * per) & 0xFF);
	return (r + g + b);
}

void		my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int*)dst = color;
}

static void	check_endgame(t_cub3d *cub)
{
	if (cub->tex.g_o.g_o == 0)
		game_over(cub);
	if (cub->tex.y_w.g_o == 0)
		you_win(cub);
}

static void	print_hud(t_cub3d *cub)
{
	print_weap(cub);
	print_lifebarre(cub);
	if (cub->tex.lifbar.hp == 0)
		print_over_win(cub, 0);
	if (cub->map.nb_goal_start == 1 && cub->map.nb_goal == 0)
		print_over_win(cub, 1);
}

void		display(t_cub3d *cub)
{
	if (cub->pars.save == 0)
	{
		check_endgame(cub);
		mlx_put_image_to_window(cub->map.mlx_ptr, cub->map.mlx_win,
					cub->img.img, 0, 0);
		mlx_string_put(cub->map.mlx_ptr, cub->map.mlx_win,
						cub->pars.scrwidth / 2, cub->pars.scrheight / 2,
						0xffffff, "X");
		if (cub->pars.scrheight > 300 && cub->pars.scrwidth > 300)
			put_mini_map(cub);
		print_hud(cub);
		if (cub->bool == 1)
			ft_printf("%sGOOD GAME %s:D\n", CYAN, YELLOW);
		cub->bool = 0;
	}
	else
		save(cub);
}
