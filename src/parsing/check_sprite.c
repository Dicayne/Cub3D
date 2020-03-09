/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:26:49 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/09 19:22:18 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	find_sprit(t_sp **sp, t_map *map)
{
	int y;
	int i;
	int x;

	y = 0;
	i = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 2)
			{
				(*sp)[i].x = x + 0.5;
				(*sp)[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void	set_sprite_tab(t_sp **sp, t_map *map)
{
	int i;

	i = 0;
	while (i < map->nb_sprit)
	{
		(*sp)[i].x = 0;
		(*sp)[i].y = 0;
		i++;
	}
}

t_sp		*fill_sprit(t_map *map)
{
	t_sp *sp;

	sp = (t_sp *)malloc(sizeof(t_sp) * map->nb_sprit);
	set_sprite_tab(&sp, map);
	find_sprit(&sp, map);
	return (sp);
}
