/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:45:57 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/07 12:58:40 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

int			close_prog(t_cub3d *cub)
{
	ft_printf("%sSee you soon %s:'( %s\n", CYAN, YELLOW, NC);
	mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
	mlx_destroy_window(cub->map.mlx_ptr, cub->map.mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

int			key_release(int keycode, t_move *move)
{
	if (keycode == W)
		move->w_on = 0;
	if (keycode == S)
		move->s_on = 0;
	if (keycode == A)
		move->a_on = 0;
	if (keycode == D)
		move->d_on = 0;
	if (keycode == G)
		move->g_on = 0;
	if (keycode == DR)
		move->dr_on = 0;
	return (0);
}

int			key_push(int keycode, t_move *move)
{
	if (keycode == W)
		move->w_on = 1;
	if (keycode == S)
		move->s_on = 1;
	if (keycode == A)
		move->a_on = 1;
	if (keycode == D)
		move->d_on = 1;
	if (keycode == G)
		move->g_on = 1;
	if (keycode == DR)
		move->dr_on = 1;
	if (keycode == 17 && move->dm == 0)
		move->dm = 1;
	else if (keycode == 17 && move->dm == 1)
		move->dm = 0;
	return (0);
}

int			key_hook(int keycode, t_cub3d *cub)
{
	key_push(keycode, &cub->move);
	if (keycode == 53)
		close_prog(cub);
	if (keycode == 78 && cub->spe.rot_spe + RS > 0.0051)
		cub->spe.rot_spe -= 0.005;
	if (keycode == 69 && cub->spe.rot_spe + RS < 0.25)
		cub->spe.rot_spe += 0.005;
	if (keycode == 125 && cub->spe.mov_spe + MS > 0.05)
		cub->spe.mov_spe -= 0.01;
	if (keycode == 126 && cub->spe.mov_spe + MS < 0.5)
		cub->spe.mov_spe += 0.01;
	if (keycode == F)
		save(cub);
	return (0);
}

void		event(t_cub3d *cub)
{
	init_move_ev(&cub->move);
	init_speed(&cub->spe);
	mlx_hook(cub->map.mlx_win, 3, 1L << 1, key_release, &cub->move);
	mlx_hook(cub->map.mlx_win, 2, 1L << 0, key_hook, cub);
	mlx_hook(cub->map.mlx_win, 17, 1L << 17, close_prog, cub);
	mlx_loop_hook(cub->map.mlx_ptr, refresh, cub);
}
