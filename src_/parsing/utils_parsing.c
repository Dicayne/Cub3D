/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:12:15 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/10 12:34:40 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

/*
** A DEGAGER
*/

void	print_int(t_map *coor)
{
	int y;
	int x;

	y = 0;
	while (y < coor->y)
	{
		x = 0;
		while (x < coor->x)
		{
			ft_putnbr(coor->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

/*
** A DEGAGER
*/

int		strlen_c(char *str, char c, char d)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		str[i] != c && str[i] != d ? ret++ : ret;
		i++;
	}
	return (ret);
}

void	fill_8(int **map, int x, int y, int max)
{
	while (x < max)
	{
		map[y][x] = 0;
		x++;
	}
}

void	from_0_to_8(t_map *map, int y, int x)
{
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 0 || map->map[y][x] == 2)
			{
				if (y == 0 || y == map->y - 1 || x == map->x - 1 || x == 0)
					map->map[y][x] = 8;
			}
			if (map->map[y][x] == 11)
				map->map[y][x] = 8;
			x++;
		}
		y++;
	}
}

int		strisnum(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			return (-1);
	}
	return (1);
}