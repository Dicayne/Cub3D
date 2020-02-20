/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:18:11 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/20 10:19:45 by vmoreau          ###   ########.fr       */
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
	// void *img;
	// void *img2;
	// int img_h;
	// int img_w;
	// int x;
	// int y;

	// img = mlx_xpm_file_to_image(cub->map.mlx_ptr, cub->pars.pars_no, &img_w, &img_h);
	// img2 = mlx_xpm_file_to_image(cub->map.mlx_ptr, cub->pars.pars_so, &img_w, &img_h);
	// y = 0;
	// while (y < cub->pars.scrheight - 1)
	// {
	// 	x = 0;
	// 	while (x < cub->pars.scrwidth - 1)
	// 	{
	// 		mlx_put_image_to_window(cub->map.mlx_ptr, cub->map.mlx_win, img2, x, y);
	// 		x += 60;
	// 	}
	// 	y += 60;
	// }
	// mlx_put_image_to_window(cub->map.mlx_ptr, cub->map.mlx_win, img, 0, 0);
	event(cub);
	print_map(cub);
	mlx_loop(cub->map.mlx_ptr);
}
