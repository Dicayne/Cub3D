/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:10:14 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/07 17:21:19 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	pars_texture(char **split, t_path *pars)
{
	if (ft_strcmp(split[0], "NO") == 0)
		pars->pars_no = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "SO") == 0)
		pars->pars_so = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "WE") == 0)
		pars->pars_we = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "EA") == 0)
		pars->pars_ea = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "S") == 0)
		pars->pars_s = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "F") == 0)
		pars->pars_f = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "C") == 0)
		pars->pars_c = ft_strdup(split[1]);
	else
		return (-1);
	if (split[2] != NULL)
		return (-1);
	else
		return (0);
}

static int	pars_line(char **split, t_path *pars)
{
	int ret;

	if (split[0] == '\0')
		ret = 0;
	else if (ft_strcmp(split[0], "R") == 0)
	{
		pars->scrwidth = ft_atoi(split[1]);
		pars->scrheight = ft_atoi(split[2]);
		ret = 0;
	}
	else if (ft_strcmp(split[0], "NO") == 0 || ft_strcmp(split[0], "SO") == 0 ||
			 ft_strcmp(split[0], "WE") == 0 || ft_strcmp(split[0], "EA") == 0 ||
			 ft_strcmp(split[0], "S") == 0 || ft_strcmp(split[0], "F") == 0 ||
			 ft_strcmp(split[0], "C") == 0)
		ret = pars_texture(split, pars);
	else if (pars->scrheight != 0 && pars->scrwidth != 0 &&
			 pars->pars_no != NULL && pars->pars_so != NULL &&
			 pars->pars_ea != NULL && pars->pars_we != NULL && 
			 pars->pars_s != NULL && pars->pars_f != NULL &&
			 pars->pars_c != NULL && (split[0][0] >= '1' && split[0][0] <= '9'))
		ret = 1;
	else
		ret = -1;
	return (ret);
}

int			parsing_fd(t_path *pars, t_map *map, char *fdm)
{
	int		fd;
	char	*str;
	int		ret;
	int		ret2;
	char	**split;
	
	str = NULL;
	ret = 1;
	ret2 = 0;
	init_struct(pars, map);
	fd = open(fdm, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		if (ret == -1)
			break;
		split = ft_split(str, ' ');
		ret2 = pars_line(split, pars);
		if (ret2 != 1)
			free(str);
		free_split(split);
		if (ret2 == -1 || ret2 == 1)
			break;
	}
	if (ret2 == 1)
	{
		ret = pars_map(map, fd, str);
		free(str);
	}
	ret2 == -1 ? ret = ret2 : ret;
	return (ret);
}