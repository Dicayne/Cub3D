/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:04:21 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/20 17:22:56 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static void	move_d(t_cub3d *cub)
{
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * MS))]
					[(int)(cub->map.pos_x + (cub->cast.plane.x_f * MS))] == 0)
	{
		cub->map.pos_y += cub->cast.plane.y_f * MS;
		cub->map.pos_x += cub->cast.plane.x_f * MS;
	}
	else
	{
		if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * MS))]
					[(int)cub->map.pos_x] == 0)
			cub->map.pos_y += cub->cast.plane.y_f * MS;
		if (cub->map.map[(int)cub->map.pos_y]
					[(int)(cub->map.pos_x + (cub->cast.plane.x_f * MS))] == 0)
			cub->map.pos_x += cub->cast.plane.x_f * MS;
	}
}

static void	move_a(t_cub3d *cub)
{
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * MS))]
					[(int)(cub->map.pos_x - (cub->cast.plane.x_f * MS))] == 0)
	{
		cub->map.pos_y -= cub->cast.plane.y_f * MS;
		cub->map.pos_x -= cub->cast.plane.x_f * MS;
	}
	else
	{
		if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * MS))]
					[(int)cub->map.pos_x] == 0)
			cub->map.pos_y -= cub->cast.plane.y_f * MS;
		if (cub->map.map[(int)cub->map.pos_y]
					[(int)(cub->map.pos_x - (cub->cast.plane.x_f * MS))] == 0)
			cub->map.pos_x -= cub->cast.plane.x_f * MS;
	}
}

void		move_a_d(t_cub3d *cub, int keycode)
{
	if (keycode == A)
		move_a(cub);
	if (keycode == D)
		move_d(cub);
}
