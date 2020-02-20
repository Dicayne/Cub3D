/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:55:43 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/20 17:46:12 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static void	move_w(t_cub3d *cub)
{
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * MS))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * MS))] == 0)
	{
		cub->map.pos_y += cub->cast.dir.y_f * MS;
		cub->map.pos_x += cub->cast.dir.x_f * MS;
	}
	else
	{
		if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * MS))]
					[(int)cub->map.pos_x] == 0)
			cub->map.pos_y += cub->cast.dir.y_f * MS;
		if (cub->map.map[(int)cub->map.pos_y]
						[(int)(cub->map.pos_x + (cub->cast.dir.x_f * MS))] == 0)
			cub->map.pos_x += cub->cast.dir.x_f * MS;
	}
}

static void	move_s(t_cub3d *cub)
{
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * MS))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * MS))] == 0)
	{
		cub->map.pos_y -= cub->cast.dir.y_f * MS;
		cub->map.pos_x -= cub->cast.dir.x_f * MS;
	}
	else
	{
		if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * MS))]
					[(int)cub->map.pos_x] == 0)
			cub->map.pos_y -= cub->cast.dir.y_f * MS;
		if (cub->map.map[(int)cub->map.pos_y]
						[(int)(cub->map.pos_x - (cub->cast.dir.x_f * MS))] == 0)
			cub->map.pos_x -= cub->cast.dir.x_f * MS;
	}
}

void		move_w_s(t_cub3d *cub, int keycode)
{
	if (keycode == W)
		move_w(cub);
	if (keycode == S)
		move_s(cub);
}
