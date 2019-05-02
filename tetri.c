/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:57:54 by thallot           #+#    #+#             */
/*   Updated: 2019/05/01 12:37:52 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_place_min(char *str, int min_x, int min_y)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(i % 5) < min_x ? min_x = (i % 5) : min_x;
			(i / 5) < min_y ? min_y = (i / 5) : min_y;
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			str[i] = '.';
			str[i - min_x - (min_y * 5)] = '#';
		}
		i++;
	}
	return (str);
}

int		*ft_get_size(char *str)
{
	int i;
	int max_width;
	int max_height;
	int	*size;

	max_width = 0;
	max_height = 0;
	i = 0;
	if (!(size = (int *)ft_memalloc(sizeof(int) * 2)))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(i % 5) > max_width ? max_width = (i % 5) : max_width;
			(i / 5) > max_height ? max_height = (i / 5) : max_height;
		}
		i++;
	}
	size[0] = max_width + 1;
	size[1] = max_height + 1;
	return (size);
}

t_tetri	*ft_create_tetri(char *str, int index)
{
	int		i;
	int		compteur;
	t_tetri	*tetri;
	int		*size;

	i = -1;
	compteur = 0;
	if (!(tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri))))
		return (NULL);
	str = ft_place_min(str, 4, 4);
	size = ft_get_size(str);
	tetri->width = size[0];
	tetri->height = size[1];
	tetri->str = ft_strdup(str);
	tetri->index = index;
	while (compteur < 4 && str[++i] != '\0')
	{
		if (str[i] == '#')
		{
			tetri->pos[compteur][0] = i % 5;
			tetri->pos[compteur++][1] = i / 5;
		}
	}
	ft_memdel((void **)&size);
	return (tetri);
}

t_tetri	**ft_create_list(char **tetris)
{
	int		i;
	t_tetri **tetri;

	i = 0;
	if (!(tetri = (t_tetri **)ft_memalloc(sizeof(t_tetri *) * 27)))
		return (NULL);
	while (tetris[i])
	{
		tetri[i] = ft_create_tetri(tetris[i], i);
		i++;
	}
	ft_free_tab(tetris, i);
	return (tetri);
}
