/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:55:43 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/11 17:40:26 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static void	move_w(t_cub3d *cub)
{
	double spd;
	static int time;

	spd = MS + cub->spe.mov_spe;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
				[(int)cub->map.pos_x] == 0)
		cub->map.pos_y += cub->cast.dir.y_f * spd;
	if (cub->map.map[(int)cub->map.pos_y]
				[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 0)
		cub->map.pos_x += cub->cast.dir.x_f * spd;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 0)
		 time = 1;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 1 ||
		cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 2)
		if (time == 1)
		{
			ft_putchar('\a');
			time = 0;
		}
}

static void	move_s(t_cub3d *cub)
{
	double spd;
	static int time;

	spd = MS + cub->spe.mov_spe;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
				[(int)cub->map.pos_x] == 0)
		cub->map.pos_y -= cub->cast.dir.y_f * spd;
	if (cub->map.map[(int)cub->map.pos_y]
				[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 0)
		cub->map.pos_x -= cub->cast.dir.x_f * spd;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 0)
		 time = 1;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 1 ||
		cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 2)
		if (time == 1)
		{
			ft_putchar('\a');
			time = 0;
		}
}

void		move_w_s(t_cub3d *cub, int keycode)
{
	if (keycode == W)
		move_w(cub);
	if (keycode == S)
		move_s(cub);
}
