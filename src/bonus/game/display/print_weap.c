/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_weap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:55:26 by vmoreau           #+#    #+#             */
/*   Updated: 2020/05/27 18:41:30 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void		init_weap(t_cub3d *cub)
{
	free(cub->tex.weap.path);
	free_tab_int(&cub->tex.weap);
	if (cub->move.shot == 0)
		cub->tex.weap.path = ft_strdup("./texture/sprite/shotgun.xpm");
	else
		cub->tex.weap.path = ft_strdup("./texture/sprite/shotgun2.xpm");
	if (get_img_info(
			&cub->tex.weap, cub->map.mlx_ptr, cub->tex.weap.path) == -1)
		close_prog(cub);
}

static void		init_img_weap(t_cub3d *cub, t_image *weap)
{
	weap->img_h = cub->pars.scrheight / 2;
	weap->img_w = cub->pars.scrwidth / 2.5;
	weap->img = mlx_new_image(cub->map.mlx_ptr, weap->img_w, weap->img_h);
	weap->adr = mlx_get_data_addr(weap->img, &weap->bits_per_pixel,
					&weap->line_length, &weap->endian);
}

static void		print(t_image *weap, t_cub3d *cub)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < weap->img_h)
	{
		x = 0;
		while (x < weap->img_w)
		{
			color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.weap.tiadr[(cub->tex.weap.img_h * y) / weap->img_h]
									[(cub->tex.weap.img_w * x) / weap->img_w]);
			my_mlx_pixel_put(weap, x, y, color);
			x++;
		}
		y++;
	}
}

void			print_weap(t_cub3d *cub)
{
	t_image weap;

	init_weap(cub);
	init_img_weap(cub, &weap);
	print(&weap, cub);
	mlx_put_image_to_window(cub->map.mlx_ptr, cub->map.mlx_win,
					weap.img, cub->pars.scrwidth / 2 - (weap.img_w / 6),
					cub->pars.scrheight - (weap.img_h + 2));
}
