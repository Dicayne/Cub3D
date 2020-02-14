/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:05:43 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/14 15:30:42 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	init_dir(t_map *map, t_coor_vec *dir)
{
	if (map->dir == 'N')
	{
		dir->x = 0.0;
		dir->y = -1.0;
	}
	else if (map->dir == 'S')
	{
		dir->x = 0.0;
		dir->y = 1.0;
	}
	else if (map->dir == 'W')
	{
		dir->x = -1.0;
		dir->y = 0.0;
	}
	else if (map->dir == 'E')
	{
		dir->x = 1.0;
		dir->y = 0.0;
	}
}

void	init_plane(t_coor_vec dir, t_coor_vec *plane)
{
	int bool_x = 0;
	int bool_y = 0;
	if (dir.x != 0)
		bool_y = 1;
	else
		bool_x = 1;
	plane->x = bool_x * tan(FOV/2);
	plane->y = bool_y * tan(FOV/2);
}

