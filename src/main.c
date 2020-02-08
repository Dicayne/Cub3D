/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:16:18 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/08 20:32:39 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int main(int ac, char **av)
{
	t_path pars;
	t_map map;
	t_data	data;

	if (ac < 2)
	{
		ft_putstr("Arguments ERROR\n");
		return (0);
	}
	if (parsing_fd(&pars, &map, av[1]) == -1)
	{
		ft_putstr("ERROR\n");
		ft_putstr(pars.error);
	}
	else
	{
		print_int(&map);
		printf("pos_x:%d pos_y:%d dir:%c\n", map.pos_x, map.pos_y, map.dir);
		printf("Reso:%d %d\n\nTexture:\n", pars.scrwidth, pars.scrheight);
		printf("no:%s\nso:%s\nea:%s\nwe:%s\ns:%s\nf:%s\nc:%s\n", pars.pars_no, pars.pars_so, pars.pars_ea, pars.pars_we, pars.pars_s, pars.pars_f, pars.pars_c);
		printf("Parsing OK\n");
		if ((data.mlx_ptr = mlx_init()) == NULL)
			return (EXIT_FAILURE);
		if ((data.mlx_win = mlx_new_window(data.mlx_ptr, SCRWIDTH, SCRHEIGHT, "Cub3D")) == NULL)
			return (EXIT_FAILURE);
		print_map(map, pars, &data);
		mlx_loop(data.mlx_ptr);
	}
	free_struct(&pars, &map);
	system ("leaks Cub3D");
	return (0);
}
