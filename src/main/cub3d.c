/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:18:11 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/14 14:02:23 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void start(t_path pars, t_map *map, t_data *data)
{
	// // (void)pars;
	// // (void)map;
	// // (void)data;
	// if ((data->mlx_ptr = mlx_init()) == NULL)
	// 	exit (EXIT_FAILURE);
	// if ((data->mlx_win = mlx_new_window(data->mlx_ptr, pars.scrwidth, pars.scrheight, "Cub3D")) == NULL)
	// 	exit (EXIT_FAILURE);
	// mlx_key_hook(data->mlx_win, key_hook, data);
	print_map(map, pars, data);
	// mlx_loop(data->mlx_ptr);
}
