/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:16:18 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/11 18:10:06 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	display_parsing(t_path pars, t_map map)
{
	print_int(&map);
	ft_printf("pos_x:%f pos_y:%f dir:%c\n", map.pos_x, map.pos_y, map.dir);
	ft_printf("Reso:%d %d\n\nTexture:\n", pars.scrwidth, pars.scrheight);
	ft_printf("no:%s\nso:%s\nea:%s\nwe:%s\ns:%s\nf:%s\nc:%s\n", pars.pars_no,
			pars.pars_so, pars.pars_ea, pars.pars_we, pars.pars_s, pars.pars_f,
			pars.pars_c);
	ft_printf("Parsing OK\n");
}

int		main(int ac, char **av)
{
	t_cub3d cub;

	cub.pars.save = 0;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
		{
			ft_printf("%sError\n%sArguments ERROR\n", RED, YELLOW);
			return (0);
		}
		else if (ac == 3)
			cub.pars.save = 1;
		if (parsing_fd(&cub.pars, &cub.map, av[1]) == -1)
			ft_printf("%sError\n%s%s", RED, YELLOW, cub.pars.error);
		else
			start(&cub);
	}
	else
		ft_printf("%sError\n%sArguments ERROR\n", RED, YELLOW);
	return (0);
}
