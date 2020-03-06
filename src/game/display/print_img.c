/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:01:58 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/06 16:31:48 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static int	find_pos_y(t_print *print, t_cub3d *cub, t_image *tex)
{
	int		y;
	double	step;
	double	tex_pos;

	y = 0;
	step = 1.0 * tex->img_h / print->line_height;
	tex_pos = (print->draw_start - cub->pars.scrheight / 2
										+ print->line_height / 2) * step;
	if (print->line_height < cub->pars.scrheight)
		return (print->y * tex->img_h / print->line_height);
	else
		return (((int)tex_pos & tex->img_h - 1) + step);
}

static void	find_color(int side, t_print *print, t_cub3d *cub)
{
	if (side == 3)
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
			cub->tex.tex_no.tiadr[find_pos_y(print, cub, &cub->tex.tex_no)]
				[(cub->cast.pos_tex.y_i * cub->tex.tex_no.img_w) / 1000]);
	else if (side == 1)
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.tex_so.tiadr[find_pos_y(print, cub, &cub->tex.tex_so)]
					[(cub->cast.pos_tex.y_i * cub->tex.tex_so.img_w) / 1000]);
	else if (side == 0)
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.tex_ea.tiadr[find_pos_y(print, cub, &cub->tex.tex_ea)]
					[(cub->cast.pos_tex.x_i * cub->tex.tex_ea.img_w) / 1000]);
	else if (side == 2)
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.tex_we.tiadr[find_pos_y(print, cub, &cub->tex.tex_we)]
					[(cub->cast.pos_tex.x_i * cub->tex.tex_we.img_w) / 1000]);
	else if (side == 5)
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.tex_s.tiadr[find_pos_y(print, cub, &cub->tex.tex_s)]
					[(cub->cast.pos_tex.x_i * cub->tex.tex_s.img_w) / 1000]);
	if (cub->move.dm == 1)
		print->color = darkness_mode(print->color, print->wall_dist);
}

static void	print_img3(t_print *print, t_cub3d *cub, int side, int x)
{
	while (print->start < print->draw_start)
	{
		if (cub->move.dm == 1)
			my_mlx_pixel_put(&cub->img, x, print->start, 0);
		else
			my_mlx_pixel_put(&cub->img, x, print->start, print->color_sky);
		print->start++;
	}
	while (print->draw_start < print->draw_end)
	{
		find_color(side, print, cub);
		my_mlx_pixel_put(&cub->img, x, print->draw_start, print->color);
		print->draw_start++;
		print->y++;
	}
	while (print->draw_end < cub->pars.scrheight - 1)
	{
		if (cub->move.dm == 1)
			my_mlx_pixel_put(&cub->img, x, print->draw_end, 0);
		else
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
	print.y = 0;
	init_world_color(cub, &print.color_sky, &print.color_floor);
	print_img3(&print, cub, side, x);
}

void		print_img(double wall_dist, int side, t_cub3d *cub, int x)
{
	cub->cast.pos_tex.x_f = cub->map.pos_y + wall_dist * cub->cast.ray_dir.y_f;
	cub->cast.pos_tex.y_f = cub->map.pos_x + wall_dist * cub->cast.ray_dir.x_f;
	cub->cast.pos_tex.x_i = (cub->cast.pos_tex.x_f -
								(int)cub->cast.pos_tex.x_f) * 1000;
	cub->cast.pos_tex.y_i = (cub->cast.pos_tex.y_f -
								(int)cub->cast.pos_tex.y_f) * 1000;
	print_img2(wall_dist, side, cub, x);
}
