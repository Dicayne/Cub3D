/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:29:09 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/21 19:06:41 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int*)dst = color;
}

static void	print_y(double wall_dist, int side, t_cub3d *cub, int x)
{
	int line_height;
	int draw_start;
	int draw_end;
	int color;
	int y;
	int color_sky;
	int color_floor;

	y = 0;
	line_height = (int)(cub->pars.scrheight / wall_dist);
	draw_start = -line_height / 2 + cub->pars.scrheight / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + cub->pars.scrheight / 2;
	if (draw_end >= cub->pars.scrheight)
		draw_end = cub->pars.scrheight - 1;
	//if (x == cub->pars.scrwidth / 2)
	printf("x:%d   y:%d\n", cub->cast.pos_tex.x_i, cub->cast.pos_tex.y_i);
	if (side == 1)
		color = mlx_get_color_value(cub->map.mlx_ptr, cub->tex.tex_no.iadr[cub->cast.pos_tex.x_i]);
	else
		color = mlx_get_color_value(cub->map.mlx_ptr, cub->tex.tex_so.iadr[cub->cast.pos_tex.y_i]);
	init_world_color(cub, &color_sky, &color_floor);
	while (y < draw_start)
	{
		my_mlx_pixel_put(&cub->img, x, y, color_sky);
		y++;
	}
	while (draw_start < draw_end)
	{
		my_mlx_pixel_put(&cub->img, x, draw_start, color);
		draw_start++;
	}
	while (draw_end < cub->pars.scrheight - 1)
	{
		my_mlx_pixel_put(&cub->img, x, draw_end, color_floor);
		draw_end++;
	}
}

static void	prep_ray_cast2(t_cast *cast, t_map map)
{
	if (cast->ray_dir.x_f < 0)
	{
		cast->step.x_i = -1;
		cast->side_dist.x_f = (map.pos_x - cast->map.x_i) *
								cast->delta_dist.x_f;
	}
	else
	{
		cast->step.x_i = 1;
		cast->side_dist.x_f = (cast->map.x_i + 1.0 - map.pos_x) *
								cast->delta_dist.x_f;
	}
	if (cast->ray_dir.y_f < 0)
	{
		cast->step.y_i = -1;
		cast->side_dist.y_f = (map.pos_y - cast->map.y_i) *
								cast->delta_dist.y_f;
	}
	else
	{
		cast->step.y_i = 1;
		cast->side_dist.y_f = (cast->map.y_i + 1.0 - map.pos_y) *
								cast->delta_dist.y_f;
	}
}

static void	prep_ray_cast(t_cast *cast, t_path pars, int x, t_map map)
{
	init_camera(cast, pars, x);
	cast->map.x_i = map.pos_x;
	cast->map.y_i = map.pos_y;
	cast->delta_dist.y_f = sqrt(1 + (cast->ray_dir.x_f * cast->ray_dir.x_f) /
									(cast->ray_dir.y_f * cast->ray_dir.y_f));
	cast->delta_dist.x_f = sqrt(1 + (cast->ray_dir.y_f * cast->ray_dir.y_f) /
									(cast->ray_dir.x_f * cast->ray_dir.x_f));
	prep_ray_cast2(cast, map);
}

static void	ray_throw(t_cast *cast, t_map map, int *side)
{
	int	hit;

	cast->pos_tex.x_i = (int)(cast->side_dist.x_f * 100) % 10;
	cast->pos_tex.y_i = (int)(cast->side_dist.y_f * 100) % 10;
	hit = 0;
	while (hit == 0)
	{
		if (cast->side_dist.x_f < cast->side_dist.y_f)
		{
			cast->side_dist.x_f += cast->delta_dist.x_f;
			cast->map.x_i += cast->step.x_i;
			*side = 0;
		}
		else
		{
			cast->side_dist.y_f += cast->delta_dist.y_f;
			cast->map.y_i += cast->step.y_i;
			*side = 1;
		}
		if (map.map[cast->map.y_i][cast->map.x_i] == 1)
			hit = 1;
	}
	printf("x:%f   y:%f\n", cast->side_dist.x_f, cast->side_dist.y_f);
}

void		print_map(t_cub3d *cub)
{
	int			x;
	double		wall_dist;
	int			side;

	init_img_struct(cub);
	if (cub->bool == 1)
	{
		init_dir(cub->map, &cub->cast);
		init_plane(&cub->cast);
		cub->bool = 0;
	}
	x = 0;
	while (x < cub->pars.scrwidth)
	{
		prep_ray_cast(&cub->cast, cub->pars, x, cub->map);
		ray_throw(&cub->cast, cub->map, &side);
		if (side == 0)
			wall_dist = (cub->cast.map.x_i - cub->map.pos_x +
						(1 - cub->cast.step.x_i) / 2) / cub->cast.ray_dir.x_f;
		else
			wall_dist = (cub->cast.map.y_i - cub->map.pos_y +
						(1 - cub->cast.step.y_i) / 2) / cub->cast.ray_dir.y_f;
		print_y(wall_dist, side, cub, x);
		x++;
	}
	mlx_put_image_to_window(cub->map.mlx_ptr, cub->map.mlx_win, cub->img.img, 0, 0);
}
