/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:34:12 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/03 10:29:10 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int*)dst = color;
}

void		display(t_cub3d *cub)
{
	mlx_put_image_to_window(cub->map.mlx_ptr, cub->map.mlx_win, cub->img.img, 0, 0);
	mlx_string_put(cub->map.mlx_ptr, cub->map.mlx_win, cub->pars.scrwidth / 2,
					cub->pars.scrheight / 2, 0xffffff, "X");
	if (cub->pars.scrheight > 300 && cub->pars.scrwidth > 300)
		put_mini_map(cub);
}
