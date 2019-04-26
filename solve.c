/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:19:54 by thallot           #+#    #+#             */
/*   Updated: 2019/04/26 13:44:09 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_place_piece(t_map *map, t_tetri *tetri, int x, int y)
{
	int i;
	int count;
	int start;

	i = 0;
	count = 0;
	start = 0;
	while (i < 4)
	{
		if (map->map[y + tetri->pos[i][1]][x + tetri->pos[i][0]] == '.' && count == i)
		{
			count++;
			map->map[y + tetri->pos[i][1]][x + tetri->pos[i][0]] = '#';
		}
		i++;
	}
	if (count == 4)
		return (1);
	return (0);
}
