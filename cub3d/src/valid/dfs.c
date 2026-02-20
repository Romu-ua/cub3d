/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:17:54 by hyamamot          #+#    #+#             */
/*   Updated: 2026/02/20 14:17:54 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"

static int	get_row_width(int *row)
{
	int	width;

	width = 0;
	while (row[width] != -1)
		width++;
	return (width);
}

static bool	is_on_boundary(int pos[2], int width, int height)
{
	if (pos[0] <= 0 || pos[0] >= height - 1)
		return (true);
	if (pos[1] <= 0 || pos[1] >= width - 1)
		return (true);
	return (false);
}

static void	dfs_step(int **map, int npos[2], bool *out_of_map, int height)
{
	if (map[npos[0]][npos[1]] == 1)
		return ;
	if (map[npos[0]][npos[1]] == 2)
	{
		*out_of_map = true;
		return ;
	}
	map[npos[0]][npos[1]] = 1;
	dfs(map, npos, out_of_map, height);
}

void	dfs(int **map, int pos[2], bool *out_of_map, int height)
{
	int				i;
	int				npos[2];
	int				width;
	static int		move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	if (*out_of_map)
		return ;
	width = get_row_width(map[pos[0]]);
	if (is_on_boundary(pos, width, height))
	{
		*out_of_map = true;
		return ;
	}
	i = 0;
	while (i < 4 && !*out_of_map)
	{
		npos[0] = pos[0] + move[i][0];
		npos[1] = pos[1] + move[i][1];
		dfs_step(map, npos, out_of_map, height);
		i++;
	}
}
