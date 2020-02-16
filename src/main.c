/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:16:18 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/15 14:11:46 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void display_parsing(t_path pars, t_map map)
{
	print_int(&map);
	printf("pos_x:%f pos_y:%f dir:%c\n", map.pos_x, map.pos_y, map.dir);
	printf("Reso:%d %d\n\nTexture:\n", pars.scrwidth, pars.scrheight);
	printf("no:%s\nso:%s\nea:%s\nwe:%s\ns:%s\nf:%s\nc:%s\n", pars.pars_no, pars.pars_so, pars.pars_ea, pars.pars_we, pars.pars_s, pars.pars_f, pars.pars_c);
	printf("Parsing OK\n");
}

int main(int ac, char **av)
{
	t_path	pars;
	t_map	map;
	t_data	data;

	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
		{
			ft_putstr("ERROR\nArguments ERROR\n");
			return (0);
		}
		else if (ac == 3)
			pars.save = 1;
		if (parsing_fd(&pars, &map, av[1]) == -1)
		{
			ft_putstr("ERROR\n");
			ft_putstr(pars.error);
		}
		else
		{
			display_parsing(pars, map);
			start(pars, &map, &data);
			free_struct(&pars, &map);
		}
	}
	else
		ft_putstr("ERROR\nArguments ERROR\n");
	//system ("leaks cub3D");
	return (0);
}
