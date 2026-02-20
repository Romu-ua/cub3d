/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:10:44 by hyamamot          #+#    #+#             */
/*   Updated: 2026/02/20 15:10:44 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_H
# define VALID_H

# include "main.h"
# include <stdbool.h>
# include <stdlib.h>

int		valid(t_map *map);
void	dfs(int **map, int pos[2], bool *out_of_map, int height);

#endif
