/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:18:11 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/18 14:46:30 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	init_img_struct(t_cub3d *cub)
{	
	cub->img.img = mlx_new_image(cub->map.mlx_ptr, cub->pars.scrwidth, cub->pars.scrheight);
	cub->img.adr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
					 &cub->img.line_length,	&cub->img.endian);
}

void		start(t_cub3d *cub)
{
	cub->bool = 1;
	if ((cub->map.mlx_ptr = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	if ((cub->map.mlx_win = mlx_new_window(cub->map.mlx_ptr, cub->pars.scrwidth,
			cub->pars.scrheight, "Cub3D")) == NULL)
		exit(EXIT_FAILURE);
	mlx_hook(cub->map.mlx_win,2, 1L<<0, key_hook, cub);
	print_map(cub);
	mlx_loop(cub->map.mlx_ptr);
}
