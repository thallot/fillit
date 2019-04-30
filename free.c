/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:14:31 by thallot           #+#    #+#             */
/*   Updated: 2019/04/30 15:42:36 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_tab(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&map[i]);
		i++;
	}
	ft_memdel((void **)&map);
}

void	ft_free_map(t_map *map)
{
	ft_free_tab(map->map, map->size);
	ft_memdel((void **)&map);
}

void	ft_free_tetri(t_tetri *tetri)
{
	int i;

	i = 0;
	ft_memdel((void **)&(tetri->pos));
	ft_memdel((void **)&(tetri->str));
	ft_memdel((void **)&tetri);
}

void	ft_free_all_tetri(t_tetri **tetri)
{
	int i;

	i = 0;
	while (tetri[i])
	{
		ft_free_tetri(tetri[i]);
		i++;
	}
	ft_memdel((void **)&tetri);
}
