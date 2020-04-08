/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:16:18 by vmoreau           #+#    #+#             */
/*   Updated: 2020/04/08 16:56:47 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void		display_parsing(t_path pars, t_map map)
{
	print_int(&map);
	ft_printf("pos_x:%f pos_y:%f dir:%c\n", map.pos_x, map.pos_y, map.dir);
	ft_printf("Reso:%d %d\n\nTexture:\n", pars.scrwidth, pars.scrheight);
	ft_printf("no:%s\nso:%s\nea:%s\nwe:%s\ns:%s\nf:%s\nc:%s\n", pars.pars_no,
			pars.pars_so, pars.pars_ea, pars.pars_we, pars.pars_s, pars.pars_f,
			pars.pars_c);
	ft_printf("Parsing OK\n");
}

static int		ft_strcmp_end(const char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = ft_strlen(s2);
	j = ft_strlen(s1);
	while (i > 0)
	{
		if (s1[j] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i--;
		j--;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	if (s1[0] == '\0')
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	return (0);
}

static int	check_arg(t_cub3d *cub, int ac, char **av)
{
	if ((ac == 3 && ft_strcmp(av[2], "--save") != 0 )||
				ft_strcmp_end(av[1], ".cub") != 0)
	{
		ft_printf("%sError\n%sArguments ERROR\n", RED, YELLOW);
		return (-1);
	}
	else if (ac == 3)
		cub->pars.save = 1;
	return (0);
}

int			main(int ac, char **av)
{
	t_cub3d cub;

	cub.pars.save = 0;
	if (ac == 2 || ac == 3)
	{
		if (check_arg(&cub, ac, av) == -1)
			return (0);
		if (parsing_fd(&cub.pars, &cub.map, av[1]) == -1)
		{
			ft_printf("%sError\n%s%s%s", RED, YELLOW, cub.pars.error, NC);
			free_struct(&cub.pars, &cub.map);
		}
		else
			start(&cub);
	}
	else
		ft_printf("%sError\n%sArguments ERROR\n", RED, YELLOW);
	return (0);
}