/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:14:19 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/21 16:28:10 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	get_img_info(t_image *img, void *mlx_ptr, char *path_tex)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, path_tex, &img->img_w,
									&img->img_h);
	img->adr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								&img->line_length, &img->endian);
	img->iadr = (int*)img->adr;
}

// int			find_color_tex(int x; )
// {
	
// }

void		set_images(t_cub3d *cub)
{
	get_img_info(&cub->tex.tex_no, cub->map.mlx_ptr, cub->pars.pars_no);
	get_img_info(&cub->tex.tex_so, cub->map.mlx_ptr, cub->pars.pars_so);
	// get_img_info(&cub->tex.tex_ea, cub->map.mlx_ptr, cub->pars.pars_ea);
	// get_img_info(&cub->tex.tex_we, cub->map.mlx_ptr, cub->pars.pars_we);
}

// void *img;
// void *img2;
// int img_h;
// int img_w;
// int x;
// int y;
// int bpp;
// int ls;
// int endian;
// char *adr;
// int *toto;
// int color;
// img = mlx_xpm_file_to_image(cub->map.mlx_ptr, cub->pars.pars_no, &img_w, &img_h);
// img2 = mlx_xpm_file_to_image(cub->map.mlx_ptr, cub->pars.pars_so, &img_w, &img_h);
// adr = mlx_get_data_addr(img, &bpp, &ls, &endian);
// toto = (int *)adr;
// y = 0;
// while (y < cub->pars.scrheight - 1)
// {
// 	x = 0;
// 	while (x < cub->pars.scrwidth - 1)
// 	{
// 		color = mlx_get_color_value(cub->map.mlx_ptr, toto[x / (cub->pars.scrwidth / img_w)]);
// 		mlx_pixel_put(cub->map.mlx_ptr, cub->map.mlx_win, x, y, color);
// 		x++;
// 	}
// 	y++;
// }
