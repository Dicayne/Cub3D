/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:34:12 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/05 19:22:00 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

void		my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int*)dst = color;
}

void		display(t_cub3d *cub)
{
	if (cub->pars.save == 0)
	{
		mlx_put_image_to_window(cub->map.mlx_ptr, cub->map.mlx_win,
						cub->img.img, 0, 0);
		// mlx_put_image_to_window(cub->map.mlx_ptr, cub->map.mlx_win,
		// 			cub->tex.tex_s.img, cub->pars.scrwidth / 2,
		// 			cub->pars.scrheight / 2);
		mlx_string_put(cub->map.mlx_ptr, cub->map.mlx_win, cub->pars.scrwidth / 2,
						cub->pars.scrheight / 2, 0xffffff, "X");
		if (cub->pars.scrheight > 300 && cub->pars.scrwidth > 300)
			put_mini_map(cub);
		if (cub->bool == 1)
			ft_printf("%sGOOD GAME %s:D\n", CYAN, YELLOW);
		cub->bool = 0;
	}
	else
		save(cub);
}
