/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:16:18 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/06 11:36:25 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int key_hook(int keycode, t_data *param)
{
	if (keycode == ESC)
	{
		mlx_clear_window(param->mlx_ptr, param->mlx_win);
		mlx_destroy_window(param->mlx_ptr, param->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == W)
		printf("%d, Avancer\n", keycode);
	else if (keycode == S)
		printf("%d, Reculer\n", keycode);
	else if (keycode == D)
		printf("%d, Droite\n", keycode);
	else if (keycode == A)
		printf("%d, Gauche\n", keycode);
	return (keycode);
}

int mouse_hook(int mousecode, int x, int y, t_data *param)
{
	(void)param;
	if ((x >= 642 && x <= 1283) && (y >= 363 && y <= 720) && mousecode == 1)
	{
		printf("SUCCESS");
		mlx_clear_window(param->mlx_ptr, param->mlx_win);
		mlx_destroy_window(param->mlx_ptr, param->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else
		printf("NOPE\n");
	return (0);
}

int expose_hook(void *param)
{
	printf("%d\n", (int)param);
	return (0);
}

int main(void)
{
	t_data	data;

	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, SCRWIDTH, SCRHEIGHT, "Cub3D")) == NULL)
		return (EXIT_FAILURE);
	affimage(&data, 0x1e90ff, 0x6b8e23, 0xff4500, 0xff0000);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_mouse_hook(data.mlx_win, mouse_hook, &data);
	//mlx_expose_hook(data.mlx_win, expose_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
