/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:38:37 by hyamamot          #+#    #+#             */
/*   Updated: 2026/04/21 08:38:38 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_ns_vec(t_map *map, t_vars *vars)
{
	vars->dir_x = 0;
	vars->plane_y = 0.0;
	if (map->dir == 'N')
	{
		vars->dir_y = -1;
		vars->plane_x = 0.66;
	}
	else
	{
		vars->dir_y = 1;
		vars->plane_x = -0.66;
	}
}

void	set_ew_vec(t_map *map, t_vars *vars)
{
	vars->dir_y = 0;
	vars->plane_x = 0.0;
	if (map->dir == 'E')
	{
		vars->dir_x = 1;
		vars->plane_y = 0.66;
	}
	else
	{
		vars->dir_x = -1;
		vars->plane_y = -0.66;
	}
}
