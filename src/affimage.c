/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affimage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:12:34 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/05 14:24:29 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void affimage(t_data *data, int c1, int c2, int c3, int c4)
{
	int x;
	int y;
	int fond;
	int w;
	int z;
	double ang;
	
	x = 0;
	ang = 15.5;
	w = SCRHEIGHT / 6;
	z = SCRHEIGHT - w;
	fond = SCRWIDTH / 3;
	while (x < SCRWIDTH)
	{
		y = 0;
		while (y < SCRHEIGHT / 2)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, c1);
			y++;
		}
		while (y < SCRHEIGHT)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, c2);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < SCRWIDTH)
	{
		if (x < fond)
		{
			if (w < SCRHEIGHT / 3)
				w = ((fond - x) * tan(ang)) + (SCRHEIGHT / 3);
			y = w;
			while (y < z)
			{
				mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, c3);
				y++;
			}
			if (z > (SCRHEIGHT / 3) * 2)
				z = ((SCRHEIGHT / 3) * 2) - ((fond - x) * tan(ang));
		}
		else if (x > fond * 2)
		{
			if (w >= SCRHEIGHT / 6)
				w = ((SCRHEIGHT / 6) * 2) + ((x - fond * 2) * tan(ang));
			y = w;
			while (y < z)
			{
				mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, c3);
				y++;
			}
			if (z <= SCRHEIGHT - (SCRHEIGHT / 6))
				z = ((SCRHEIGHT / 3) * 2) - ((x - fond * 2) * tan(ang));
		}
		else
		{
			y = SCRHEIGHT / 3;
			while (y < SCRHEIGHT / 3 * 2)
			{
				mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, c4);
				y++;
			}
		}
		x++;
	}
}