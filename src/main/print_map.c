/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:29:09 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/14 15:31:39 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	print_map(t_map *map, t_path pars, t_data *data)
{
	t_coor_vec	dir;
	t_coor_vec	plane;
	t_coor_vec	ray_dir;
	double		camera_x;
	int			x;

	(void)data;
	init_dir(map, &dir);
	init_plane(dir, &plane);
	x = 0;
	while (x < pars.scrwidth)
	{
		camera_x = 2 * x / (double)pars.scrwidth - 1;
		ray_dir.x = dir.x + plane.x * camera_x;
		ray_dir.y = dir.y + plane.y * camera_x;
		x++;
	}
}
