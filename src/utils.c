/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:12:15 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/07 20:40:46 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	print(char **split)
{
	int i;

	i = 0;
	while (split[i] != NULL)
	{
		ft_putstr(split[i]);
		ft_putchar('\n');
		i++;
	}
}

int		strlen_c(char *str, char c)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		str[i] != c ? ret++ : ret;
		i++;
	}
	return (ret);
}

void	fill_8(int **map, int x, int y, int max)
{
	while (x < max)
	{
		map[y][x] = 8;
		x++;
	}
}