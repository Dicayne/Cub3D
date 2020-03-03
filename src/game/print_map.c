/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:29:09 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/03 19:59:16 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

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

static void	ray_throw(t_cast *cast, t_map map, int *side, t_image *sprit)
{
	int	hit;
	int sp_bool;

	hit = 0;
	sp_bool = 0;
	while (hit == 0)
	{
		if (cast->side_dist.x_f < cast->side_dist.y_f)
		{
			cast->side_dist.x_f += cast->delta_dist.x_f;
			cast->map.x_i += cast->step.x_i;
			if (cast->ray_dir.x_f > 0)
				*side = 0;
			else
				*side = 2;
		}
		else
		{
			cast->side_dist.y_f += cast->delta_dist.y_f;
			cast->map.y_i += cast->step.y_i;
			if (cast->ray_dir.y_f > 0)
				*side = 1;
			else
				*side = 3;
		}
		if (map.map[cast->map.y_i][cast->map.x_i] == 1)
			hit = 1;
		if (map.map[cast->map.y_i][cast->map.x_i] == 2 && sp_bool == 0)
		{
			if (*side == 1 || *side == 3)
				sprit->dist = (cast->map.y_i - map.pos_y +
						(1 - cast->step.y_i) / 2) / cast->ray_dir.y_f;
			else 
				sprit->dist = (cast->map.x_i - map.pos_x +
						(1 - cast->step.x_i) / 2) / cast->ray_dir.x_f;
			*side = 5;
			hit = 1;
		}
	}
}

void		print_map(t_cub3d *cub)
{
	int			x;
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
		ray_throw(&cub->cast, cub->map, &side, &cub->tex.tex_s);
		if (side == 0 || side == 2)
			cub->cast.wall_dist = (cub->cast.map.x_i - cub->map.pos_x +
						(1 - cub->cast.step.x_i) / 2) / cub->cast.ray_dir.x_f;
		else
			cub->cast.wall_dist = (cub->cast.map.y_i - cub->map.pos_y +
						(1 - cub->cast.step.y_i) / 2) / cub->cast.ray_dir.y_f;
		print_img(cub->cast.wall_dist, side, cub, x);
		x++;
	}
	display(cub);
}
