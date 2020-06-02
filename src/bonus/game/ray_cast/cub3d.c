/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:18:11 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/02 16:33:04 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

void	init_img_struct(t_cub3d *cub)
{
	cub->img.img = mlx_new_image(cub->map.mlx_ptr, cub->pars.scrwidth,
					cub->pars.scrheight);
	cub->img.adr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
					&cub->img.line_length, &cub->img.endian);
	cub->img.img_h = cub->pars.scrheight;
	cub->img.img_w = cub->pars.scrwidth;
	cub->img.iadr = (int*)cub->img.adr;
	tab_text(&cub->img);
}

void	corec_reso(t_cub3d *cub)
{
	int sx;
	int sy;

	mlx_get_screen_size(cub->map.mlx_ptr, &sx, &sy);
	if (cub->pars.scrwidth > sx)
		cub->pars.scrwidth = sx;
	if (cub->pars.scrheight > sy)
		cub->pars.scrheight = sy;
}

void	start(t_cub3d *cub)
{
	cub->bool = 1;
	if ((cub->map.mlx_ptr = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	corec_reso(cub);
	if (cub->pars.save == 0)
	{
		if ((cub->map.mlx_win = mlx_new_window(cub->map.mlx_ptr,
					cub->pars.scrwidth, cub->pars.scrheight, "Cub3D")) == NULL)
			exit(EXIT_FAILURE);
		set_images(cub);
		init_img_struct(cub);
		event(cub);
		mlx_loop(cub->map.mlx_ptr);
	}
	else
	{
		cub->map.mlx_win = NULL;
		set_images(cub);
		init_img_struct(cub);
		ray_cast(cub);
	}
}
