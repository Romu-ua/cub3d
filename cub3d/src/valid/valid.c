/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:17:49 by hyamamot          #+#    #+#             */
/*   Updated: 2026/02/20 14:17:50 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "utils.h"
#include "valid.h"

int	map_deep_copy(t_map *map, int ***map_copy, int height)
{
	int	i;
	int	width;

	*map_copy = (int **)malloc(sizeof(int *) * (height + 1));
	if (!map_copy)
		return (1);
	i = 0;
	while (i < height)
	{
		width = 0;
		while (map->map[i][width] != -1)
			width++;
		width++;
		(*map_copy)[i] = (int *)malloc(sizeof(int) * width);
		if (!(*map_copy)[i])
		{
			while (--i >= 0)
				free((*map_copy)[i]);
			return (free(*map_copy), 1);
		}
		ft_memcpy((*map_copy)[i], map->map[i], sizeof(int) * width);
		i++;
	}
	(*map_copy)[height] = NULL;
	return (0);
}

int	get_height(t_map *map)
{
	int	height;

	height = 0;
	while (map->map[height])
		height++;
	return (height);
}

int	valid(t_map *map)
{
	int		**map_copy;
	bool	out_of_map;
	int		height;
	int		pos[2];
	int		i;

	if (!map->map || !map->map[0])
		return (printf("Error\n"), 1);
	height = get_height(map);
	if (map_deep_copy(map, &map_copy, height))
		return (1);
	out_of_map = false;
	pos[0] = map->pos[0];
	pos[1] = map->pos[1];
	dfs(map_copy, pos, &out_of_map, height);
	i = 0;
	while (i < height)
		free(map_copy[i++]);
	free(map_copy);
	if (out_of_map)
		return (1);
	return (0);
}
