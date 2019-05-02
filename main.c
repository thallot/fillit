/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:11:51 by thallot           #+#    #+#             */
/*   Updated: 2019/05/02 09:53:23 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**tetris;
	t_tetri **t;
	t_map	*map;

	map = NULL;
	if (argc == 2)
	{
		if ((fd = ft_open(argv[1])) <= 0)
			ft_putendl("error");
		else if (!(tetris = ft_read_tetri(fd)))
			ft_putendl("error");
		else
		{
			t = ft_create_list(tetris);
			map = ft_solve(t);
			ft_print_map(map->size, map);
			ft_free_map(map);
			ft_free_all_tetri(t);
		}
	}
	else
		ft_putstr("usage : fillit source_file\n");
	return (0);
}
