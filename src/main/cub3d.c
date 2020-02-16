/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:18:11 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/15 14:12:56 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	init_world_color(t_data *data, t_path pars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < pars.scrwidth)
	{
		y = 0;
		while (y < pars.scrheight / 2)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0xf5ff);
			y++;
		}
		while (y < pars.scrheight)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0xff00);
			y++;
		}
		x++;
	}
}

void start(t_path pars, t_map *map, t_data *data)
{
	// (void)pars;
	// (void)map;
	// (void)data;
	if ((data->mlx_ptr = mlx_init()) == NULL)
		exit (EXIT_FAILURE);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, pars.scrwidth, pars.scrheight, "Cub3D")) == NULL)
		exit (EXIT_FAILURE);
	init_world_color(data, pars);
	// mlx_key_hook(data->mlx_win, key_hook, data);
	print_map(map, pars, data);
	mlx_loop(data->mlx_ptr);
}
