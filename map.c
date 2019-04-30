/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:01:21 by thallot           #+#    #+#             */
/*   Updated: 2019/04/29 12:05:56 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	if (!(map->map = (char **)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		if (!(map->map[i] = (char *)ft_memalloc(sizeof(char) * size)))
			return (NULL);
		while (j < size)
		{
			map->map[i][j] = '.';
			j++;
		}
		i++;
	}
	map->size = size;
	return (map);
}

void	ft_print_map(int size, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
