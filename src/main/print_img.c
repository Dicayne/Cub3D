/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:01:58 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/02 14:19:04 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	find_pos_y(t_print *print, t_cub3d *cub, int side)
{
	int y;
	double step;
	double texPos;
	(void)side;
	y = 0;
	step = 1.0 * 64 / print->line_height;
	texPos = (print->draw_start - cub->pars.scrheight / 2 + print->line_height / 2) * step;
	if (print->line_height < cub->pars.scrheight)
		return (print->y * 64 / print->line_height);
	else
		return (((int)texPos & 63) + step);
}

static void	print_img3(t_print *print, t_cub3d *cub, int side, int x)
{
	while (print->start < print->draw_start)
	{
		my_mlx_pixel_put(&cub->img, x, print->start, print->color_sky);
		print->start++;
	}
	while (print->draw_start < print->draw_end)
	{
		if (side == 1)
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
					cub->tex.tex_ea.tiadr[find_pos_y(print, cub, side)]
										[(cub->cast.pos_tex.y_i * 64) / 100]);
		else
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
					cub->tex.tex_we.tiadr[find_pos_y(print, cub, side)]
										[(cub->cast.pos_tex.x_i * 64) / 100]);
		my_mlx_pixel_put(&cub->img, x, print->draw_start, print->color);
		print->draw_start++;
		print->y++;
	}
	while (print->draw_end < cub->pars.scrheight - 1)
	{
		my_mlx_pixel_put(&cub->img, x, print->draw_end, print->color_floor);
		print->draw_end++;
	}
}

static void	print_img2(double wall_dist, int side, t_cub3d *cub, int x)
{
	t_print print;

	print.wall_dist = wall_dist;
	print.start = 0;
	print.line_height = cub->pars.scrheight / wall_dist;
	print.draw_start = -print.line_height / 2 + cub->pars.scrheight / 2;
	if (print.draw_start < 0)
		print.draw_start = 0;
	print.draw_end = print.line_height / 2 + cub->pars.scrheight / 2;
	if (print.draw_end >= cub->pars.scrheight)
		print.draw_end = cub->pars.scrheight - 1;
	if (print.line_height > cub->pars.scrheight)
		print.line_height = cub->pars.scrheight;
	print.y = 0;
	init_world_color(cub, &print.color_sky, &print.color_floor);
	print_img3(&print, cub, side, x);
}

void		print_img(double wall_dist, int side, t_cub3d *cub, int x)
{
	cub->cast.pos_tex.x_f = cub->map.pos_y + wall_dist * cub->cast.ray_dir.y_f;
	cub->cast.pos_tex.y_f = cub->map.pos_x + wall_dist * cub->cast.ray_dir.x_f;
	cub->cast.pos_tex.x_i = (cub->cast.pos_tex.x_f -
								(int)cub->cast.pos_tex.x_f) * 100;
	cub->cast.pos_tex.y_i = (cub->cast.pos_tex.y_f -
								(int)cub->cast.pos_tex.y_f) * 100;
	print_img2(wall_dist, side, cub, x);
}