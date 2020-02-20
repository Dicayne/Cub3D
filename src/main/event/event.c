/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:45:57 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/20 17:56:30 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

int			close_prog(t_cub3d *cub)
{
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
	return (0);
}

int			key_hook(int keycode, t_cub3d *cub)
{
	key_push(keycode, &cub->move);
	if (keycode == 53)
		close_prog(cub);
	check_key_on(cub);
	return (0);
}

void		event(t_cub3d *cub)
{
	init_move_ev(&cub->move);
	mlx_hook(cub->map.mlx_win, 3, 1L << 1, key_release, &cub->move);
	mlx_hook(cub->map.mlx_win, 2, 1L << 0, key_hook, cub);
	mlx_hook(cub->map.mlx_win, 17, 1L << 17, close_prog, cub);
}
