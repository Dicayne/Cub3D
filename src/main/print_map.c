/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:29:09 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/15 16:44:22 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	print_y(t_path pars, double wall_dist, int side, t_data *data, int x)
{
	int lineHeight;
	int drawStart;
	int drawEnd;
	int color;

	lineHeight = (int)(pars.scrheight / wall_dist);
	drawStart = -lineHeight / 2 + pars.scrheight / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + pars.scrheight / 2;
	if(drawEnd >= pars.scrheight)
		drawEnd = pars.scrheight - 1;
	if (side == 1)
		color = 0xff4500;
	else
		color = 0xff0000;
	while (drawStart < drawEnd)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, drawStart, color);
		drawStart++;
	}
}

static void	prep_ray_cast(t_cast *cast, t_path pars, int x, t_map *map)
{
	init_camera(cast, pars, x);
	cast->map.x_i = map->pos_x;
	cast->map.y_i = map->pos_y;
	cast->delta_dist.y_f = sqrt(1 + (cast->ray_dir.x_f * cast->ray_dir.x_f) / (cast->ray_dir.y_f * cast->ray_dir.y_f));
	cast->delta_dist.x_f = sqrt(1 + (cast->ray_dir.y_f * cast->ray_dir.y_f) / (cast->ray_dir.x_f * cast->ray_dir.x_f));
	if (cast->ray_dir.x_f < 0)
	{
		cast->step.x_i = -1;
		cast->side_dist.x_f = (map->pos_x - cast->map.x_i) * cast->delta_dist.x_f;
	}
	else
	{
		cast->step.x_i = 1;
		cast->side_dist.x_f = (cast->map.x_i + 1.0 - map->pos_x) * cast->delta_dist.x_f;
	}
	if (cast->ray_dir.y_f < 0)
	{
		cast->step.y_i = -1;
		cast->side_dist.y_f = (map->pos_y - cast->map.y_i) * cast->delta_dist.y_f;
	}
	else
	{
		cast->step.y_i = 1;
		cast->side_dist.y_f = (cast->map.y_i + 1.0 - map->pos_y) * cast->delta_dist.y_f;
	}
}

static void	ray_throw(t_cast *cast, t_map *map, int *side)
{
	int	hit;

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
		if (map->map[cast->map.y_i][cast->map.x_i] == 1) hit = 1;
	}
}

void		print_map(t_map *map, t_path pars, t_data *data)
{
	t_cast		cast;
	int			x;
	double		wall_dist;
	int			side;

	init_dir(map, &cast);
	init_plane(&cast);
	x = 0;
	while (x < pars.scrwidth)
	{
		prep_ray_cast(&cast, pars, x, map);
		ray_throw(&cast, map, &side);
		if (side == 0)
			wall_dist = (cast.map.x_i - map->pos_x + (1 - cast.step.x_i) / 2) / cast.ray_dir.x_f;
		else
			wall_dist = (cast.map.y_i - map->pos_y + (1 - cast.step.y_i) / 2) / cast.ray_dir.y_f;
		print_y(pars, wall_dist, side, data, x);
		x++;
	}
}
