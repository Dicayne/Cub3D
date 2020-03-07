/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:21:54 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/07 15:01:10 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static int	find_color_sp(t_print *print, t_cub3d *cub)
{
	if (cub->tex.tex_s.tiadr[find_pos_y(print, cub, &cub->tex.tex_s)]
			[(cub->cast.pos_tex.y_i * cub->tex.tex_s.img_w) / 1000] != 0 ||
		cub->tex.tex_s.tiadr[find_pos_y(print, cub, &cub->tex.tex_s)]
			[(cub->cast.pos_tex.x_i * cub->tex.tex_s.img_w) / 1000] != 0)
	{
		if (cub->cast.sprit_side == 1)
			print->color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.tex_s.tiadr[find_pos_y(print, cub, &cub->tex.tex_s)]
					[(cub->cast.pos_tex.y_i * cub->tex.tex_s.img_w) / 1000]);
		else
			print->color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.tex_s.tiadr[find_pos_y(print, cub, &cub->tex.tex_s)]
					[(cub->cast.pos_tex.x_i * cub->tex.tex_s.img_w) / 1000]);
		if (cub->move.dm == 1)
			print->color = darkness_mode(print->color, print->wall_dist);
		return (1);
	}
	else
		return (0);
}

static void	print_img3(t_print *print, t_cub3d *cub, int x)
{
	while (print->draw_start < print->draw_end)
	{
		if (find_color_sp(print, cub) == 1)
			my_mlx_pixel_put(&cub->img, x, print->draw_start, print->color);
		print->draw_start++;
		print->y++;
	}
}

static void	print_img2(t_cub3d *cub, int x)
{
	t_print print;

	print.wall_dist = cub->cast.sprit_dst;
	print.start = 0;
	print.line_height = cub->pars.scrheight / print.wall_dist;
	print.draw_start = -print.line_height / 2 + cub->pars.scrheight / 2;
	if (print.draw_start < 0)
		print.draw_start = 0;
	print.draw_end = print.line_height / 2 + cub->pars.scrheight / 2;
	if (print.draw_end >= cub->pars.scrheight)
		print.draw_end = cub->pars.scrheight - 1;
	print.y = 0;
	init_world_color(cub, &print.color_sky, &print.color_floor);
	print_img3(&print, cub, x);
}

void		print_sprit(t_cub3d *cub, int x)
{
	cub->cast.pos_tex.x_f = cub->map.pos_y + cub->cast.sprit_dst *
													cub->cast.ray_dir.y_f;
	cub->cast.pos_tex.y_f = cub->map.pos_x + cub->cast.sprit_dst *
													cub->cast.ray_dir.x_f;
	cub->cast.pos_tex.x_i = (cub->cast.pos_tex.x_f -
								(int)cub->cast.pos_tex.x_f) * 1000;
	cub->cast.pos_tex.y_i = (cub->cast.pos_tex.y_f -
								(int)cub->cast.pos_tex.y_f) * 1000;
	print_img2(cub, x);
}

double		sprit_dist(int side, t_cub3d *cub)
{
	double ret;

	if (side == 0)
			ret = (cub->cast.map.x_i - cub->map.pos_x +
						(1 - cub->cast.step.x_i) / 2) / cub->cast.ray_dir.x_f;
	else
			ret = (cub->cast.map.y_i - cub->map.pos_y +
						(1 - cub->cast.step.y_i) / 2) / cub->cast.ray_dir.y_f;
	cub->cast.sprit_side = side;
	return (ret);
}
