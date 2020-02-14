/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:16:18 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/10 17:17:27 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

	int y_size;
	int x;
	int y;
	int mx;
	int my;
	int tempy;
	int tempx;
	
	y_size = pars.scrheight / map.y;
	x_size = pars.scrwidth / map.x;
	x = 0;
	mx = 0;
	my = 0;
	while (x < pars.scrwidth)
	{
		y = 0;
		while (y < pars.scrheight)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0xeedd82);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < x_size * map.x)
	{
		y = 0;
		my = 0;
		tempx = x;
		while (y < y_size * map.y)
		{
			tempy = y;
			if (map.map[my][mx] == 1 || (my == map.pos_y && mx == map.pos_x) || map.map[my][mx] == 2)
			{
				while (y < tempy + y_size)
				{
					x = tempx;
					while (x < tempx + x_size)
					{
						if (my == map.pos_y && mx == map.pos_x)
						{
							mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0xff0000);
						}
						else if (map.map[my][mx] == 1)
							mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0x8b4513);
						else if (map.map[my][mx] == 2)
							mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0xff);
						x++;
					}
					y++;
				}
				x = tempx;
			}
			else
				y += y_size;
			my++;
		}
		mx++;
		x = tempx + x_size;
	}
