/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:19:54 by thallot           #+#    #+#             */
/*   Updated: 2019/05/01 10:33:29 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_test_piece(t_map *map, t_tetri *tetri, int pos[2])
{
	int i;
	int count;
	int x;
	int y;

	x = pos[0];
	y = pos[1];
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (map->map[y + tetri->pos[i][1]][x + tetri->pos[i][0]] == '.'
			&& count == i)
			count++;
		i++;
	}
	if (count == 4)
	{
		ft_place_piece(map, tetri, pos);
		return (1);
	}
	return (0);
}

void	ft_place_piece(t_map *map, t_tetri *tetri, int pos[2])
{
	int		i;
	int		x;
	int		y;
	char	c;

	x = pos[0];
	y = pos[1];
	i = 0;
	c = 'A' + tetri->index;
	while (i < 4)
	{
		if (map->map[y + tetri->pos[i][1]][x + tetri->pos[i][0]] == '.')
		{
			map->map[y + tetri->pos[i][1]][x + tetri->pos[i][0]] = c;
		}
		i++;
	}
}

void	ft_delete(t_map *map, t_tetri *tetri, int pos[2], int index)
{
	int		i;
	int		x;
	int		y;
	char	c;

	c = 'A' + index;
	x = pos[0];
	y = pos[1];
	i = 0;
	while (i < 4)
	{
		if (map->map[y + tetri->pos[i][1]][x + tetri->pos[i][0]] == c)
		{
			map->map[y + tetri->pos[i][1]][x + tetri->pos[i][0]] = '.';
		}
		i++;
	}
}

int		ft_solve_tetri(t_map *map, t_tetri **tetri, int index)
{
	int x;
	int y;
	int pos[2];

	if (!tetri[index])
		return (1);
	y = 0;
	while (y < map->size - tetri[index]->height + 1)
	{
		x = 0;
		while (x < map->size - tetri[index]->width + 1)
		{
			pos[0] = x;
			pos[1] = y;
			if (ft_test_piece(map, tetri[index], pos))
			{
				if (ft_solve_tetri(map, tetri, index + 1))
					return (1);
				ft_delete(map, tetri[index], pos, index);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*ft_solve(t_tetri **tetri)
{
	size_t	size;
	t_map	*map;

	size = 1;
	map = NULL;
	map = ft_create_map(size);
	while (ft_solve_tetri(map, tetri, 0) != 1)
	{
		ft_free_map(map);
		size++;
		map = ft_create_map(size);
	}
	return (map);
}
