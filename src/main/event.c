/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:45:57 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/18 19:04:22 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	kc_w_s(t_cub3d *cub, int keycode)
{
	if (keycode == W)
	{
		if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f / 11))]
						[(int)(cub->map.pos_x + (cub->cast.dir.x_f / 11))] == 0)
		{
			cub->map.pos_y += cub->cast.dir.y_f / 11;
			cub->map.pos_x += cub->cast.dir.x_f / 11;
			mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
			print_map(cub);
		}
	}
	if (keycode == S)
	{
		if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f / 11))]
						[(int)(cub->map.pos_x - (cub->cast.dir.x_f / 11))] == 0)
		{
			cub->map.pos_y -= cub->cast.dir.y_f / 11;
			cub->map.pos_x -= cub->cast.dir.x_f / 11;
			mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
			print_map(cub);
		}
	}
}

static void	kc_a_d(t_cub3d *cub, int keycode)
{
	if (keycode == D)
	{
		if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f / 11))]
			[(int)(cub->map.pos_x + (cub->cast.plane.x_f / 11))] == 0)
		{
			cub->map.pos_y += cub->cast.plane.y_f / 11;
			cub->map.pos_x += cub->cast.plane.x_f / 11;
			mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
			print_map(cub);
		}
	}
	if (keycode == A)
	{
		if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f / 11))]
			[(int)(cub->map.pos_x - (cub->cast.plane.x_f / 11))] == 0)
		{
			cub->map.pos_y -= cub->cast.plane.y_f / 11;
			cub->map.pos_x -= cub->cast.plane.x_f / 11;
			mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
			print_map(cub);
		}
	}
}

static void	kc_g_dr(t_cub3d *cub, int keycode)
{
	double old_dirx;
	double old_planex;
	double ang;

	ang = 0.09;
	if (keycode == G)
		ang = -0.09;
	old_dirx = cub->cast.dir.x_f;
	old_planex = cub->cast.plane.x_f;
	cub->cast.dir.x_f =
			cub->cast.dir.x_f * cos(ang) - cub->cast.dir.y_f * sin(ang);
	cub->cast.dir.y_f =
			old_dirx * sin(ang) + cub->cast.dir.y_f * cos(ang);
	cub->cast.plane.x_f =
			cub->cast.plane.x_f * cos(ang) - cub->cast.plane.y_f * sin(ang);
	cub->cast.plane.y_f =
			old_planex * sin(ang) + cub->cast.plane.y_f * cos(ang);
	mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
	print_map(cub);
}

int			key_hook(int keycode, t_cub3d *cub)
{
	if (keycode == 53)
	{
		mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
		mlx_destroy_window(cub->map.mlx_ptr, cub->map.mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W || keycode == S)
		kc_w_s(cub, keycode);
	if (keycode == A || keycode == D)
		kc_a_d(cub, keycode);
	if (keycode == G || keycode == DR)
		kc_g_dr(cub, keycode);
	return (0);
}
