/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:03:06 by vmoreau           #+#    #+#             */
/*   Updated: 2020/04/08 16:45:24 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

void		game_over(t_cub3d *cub)
{
	system("afplay ./sound/g-o-music.wav");
	system("afplay ./sound/g-o-voice.wav");
	close_prog(cub);
}

void		you_win(t_cub3d *cub)
{
	system("afplay ./sound/y_w_music.wav");
	system("afplay ./sound/y_w_voice.wav");
	close_prog(cub);
}
