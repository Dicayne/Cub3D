/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:16:18 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/07 17:57:42 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int main(int ac, char **av)
{
	t_path pars;
	t_map map;
	
	if (ac < 2)
	{
		printf("Arguments ERROR");
		return (0);
	}
	if (parsing_fd(&pars, &map, av[1]) == -1)
	{
		printf("Parsing ERROR");
		return (0);
	}
	free_struct(&pars);
	// system ("leaks Cub3D");
	return (0);
}
