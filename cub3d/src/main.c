/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:26:02 by hyamamot          #+#    #+#             */
/*   Updated: 2026/02/20 13:26:05 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "utils.h"
#include "init.h"
#include "valid.h"
#include "raycasting.h"

int	is_cub_file(char *infile)
{
	int	len;

	len = ft_strlen(infile);
	if (len < 4)
		return (1);
	if (ft_strncmp(infile + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2 || is_cub_file(argv[1]))
		return (printf("Usage: ./cub3d {filename}.cub\n"), 1);
	ft_memset(&map, 0, sizeof(t_map));
	if (init(&map, argv[1]))
		return (1);
	if (valid(&map))
		return (printf("Error\n"), 1);
	raycasting(&map);
	map_free(&map);
	return (0);
}
