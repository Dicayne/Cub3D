/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:13:20 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/07 16:15:46 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void init_struct(t_path *pars, t_map *map)
{
	pars->scrheight = 0;
	pars->scrwidth = 0;
	pars->pars_no = NULL;
	pars->pars_so = NULL;
	pars->pars_ea = NULL;
	pars->pars_we = NULL;
	pars->pars_s = NULL;
	pars->pars_f = NULL;
	pars->pars_c = NULL;
	map->x = 0;
	map->y = 0;
}

void free_struct(t_path *pars)
{
	free(pars->pars_no);
	free(pars->pars_so);
	free(pars->pars_we);
	free(pars->pars_ea);
	free(pars->pars_s);
	free(pars->pars_f);
	free(pars->pars_c);
}