/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:26:42 by hyamamot          #+#    #+#             */
/*   Updated: 2026/02/20 13:26:42 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	player_dir(t_map *map, t_vars *vars)
{
	vars->pos_y = map->pos[0] + 0.5;
	vars->pos_x = map->pos[1] + 0.5;
	if (map->dir == 'N' || map->dir == 'S')
		set_ns_vec(map, vars);
	else
		set_ew_vec(map, vars);
}

void	sub_init_vars(t_map *map, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < MAX_HELD)
	{
		vars->hold_keys[i] = 0;
		i++;
	}
	vars->texture_path = map->textures;
	vars->color_code[0] = map->color_code[0];
	vars->color_code[1] = map->color_code[1];
	vars->map = map->map;
	vars->time_ms = get_time_ms();
}

void	clean_exit_raycasting(t_vars *vars, int tex_count)
{
	int	i;

	i = 0;
	while (i < tex_count)
	{
		if (vars->tex[i].img)
			mlx_destroy_image(vars->mlx, vars->tex[i].img);
		i++;
	}
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

int	init_vars(t_map *map, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		vars->tex[i].img = mlx_xpm_file_to_image(
				vars->mlx, map->textures[i], &vars->tex[i].w, &vars->tex[i].h);
		if (!vars->tex[i].img)
		{
			clean_exit_raycasting(vars, i);
			return (1);
		}
		vars->tex[i].addr = mlx_get_data_addr(
				vars->tex[i].img, &vars->tex[i].bits_per_pixel,
				&vars->tex[i].line_length, &vars->tex[i].endian);
		if (!vars->tex[i].addr)
		{
			clean_exit_raycasting(vars, i + 1);
			return (1);
		}
		i++;
	}
	player_dir(map, vars);
	sub_init_vars(map, vars);
	return (0);
}

void	raycasting(t_map *map)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "cub3d");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(
			vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	if (init_vars(map, &vars))
	{
		printf("Error\n");
		return ;
	}
	mlx_hook(vars.win, 2, 1L << 0, on_key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, on_key_release, &vars);
	mlx_hook(vars.win, 17, 0, on_destroy, &vars);
	mlx_loop_hook(vars.mlx, render_fram, &vars);
	mlx_loop(vars.mlx);
}
