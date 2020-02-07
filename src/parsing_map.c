/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:26:34 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/07 20:40:55 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static char	*clean_space(char **str)
{
	int i;
	int len;
	char *ret;

	i = 0;
	len = strlen_c(*str, ' ');
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	len = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] != ' ')
		{
			ret[len] = (*str)[i];
			len++;
		}
		i++;
	}
	ret[len] = '\0';
	return (ret);
}

static int	pars_map3(char **split, t_map *coor)
{
	int **map;
	int x;
	int y;

	y = 0;
	map = (int**)malloc(sizeof(int*) * coor->y);
	if (map == NULL)
			return (-1);
	while (split[y] != NULL)
	{
		x = 0;
		map[y] = (int*)malloc(sizeof(int) * coor->x);
		if (map[y] == NULL)
			return (-1);
		while (split[y][x] != '\0')
		{
			map[y][x] = split[y][x] - 48;
			x++;
		}
		if (x < coor->x)
			fill_8(map, x, y, coor->x);
		y++;
	}
	printf("\n");
	y = 0;
	while (y < coor->y)
	{
		x = 0;
		while (x < coor->x)
		{
			printf("%d ",map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	return (0);
}

static int	**pars_map2(char **split, t_map *map)
{
	int x;
	int y;
	int i;
	i = 0;
	x = 0;
	while (split[i] != NULL)
	{
		split[i] = clean_space(&split[i]);
		if (x < (int)ft_strlen(split[i]))
			x = ft_strlen(split[i]);
		i++;
	}
	y = i;
	map->x = x;
	map->y = y;
	pars_map3(split, map);
	return (map->map);
}

int		pars_map(t_map *mapp, int fd, char *str2)
{
	char	*str;
	int		ret;
	int		ret2;
	char	*join;
	char	**split;
	int		**map;

	str = NULL;
	join = ft_strdup(str2);
	ret = 1;
	ret2 = 0;
	while (ret > 0)
	{
		join = ft_strjoingnl(join, "@");
		ret = get_next_line(fd, &str);
		if (ret == -1)
			break;
		join = ft_strjoingnl(join, str);
		free(str);
	}
	split = ft_split(join, '@');
	map = pars_map2(split, mapp);
	free_split(split);
	free(join);
	return (0);
}