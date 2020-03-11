/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:04:21 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/11 17:41:40 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static void	move_d(t_cub3d *cub)
{
	double spd;
	static int time;

	spd = MS + cub->spe.mov_spe;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * spd))]
				[(int)cub->map.pos_x] == 0)
		cub->map.pos_y += cub->cast.plane.y_f * spd;
	if (cub->map.map[(int)cub->map.pos_y]
				[(int)(cub->map.pos_x + (cub->cast.plane.x_f * spd))] == 0)
		cub->map.pos_x += cub->cast.plane.x_f * spd;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.plane.x_f * spd))] == 0)
		time = 1;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.plane.x_f * spd))] == 1 ||
		cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.plane.x_f * spd))] == 2)
		if (time == 1)
		{
			ft_putchar('\a');
			time = 0;
		}
}

static void	move_a(t_cub3d *cub)
{
	double spd;
	static int time;

	spd = MS + cub->spe.mov_spe;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * spd))]
				[(int)cub->map.pos_x] == 0)
		cub->map.pos_y -= cub->cast.plane.y_f * spd;
	if (cub->map.map[(int)cub->map.pos_y]
				[(int)(cub->map.pos_x - (cub->cast.plane.x_f * spd))] == 0)
		cub->map.pos_x -= cub->cast.plane.x_f * spd;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.plane.x_f * spd))] == 0)
		time = 1;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.plane.x_f * spd))] == 1 ||
		cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.plane.x_f * spd))] == 2)
		if (time == 1)
		{
			ft_putchar('\a');
			time = 0;
		}
}

void		move_a_d(t_cub3d *cub, int keycode)
{
	if (keycode == A)
		move_a(cub);
	if (keycode == D)
		move_d(cub);
}
