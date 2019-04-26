/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:11:51 by thallot           #+#    #+#             */
/*   Updated: 2019/04/26 13:44:58 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**tetris;
	t_tetri **t;
	t_map	*map;
	int		i;

	i = 0;
	if (argc == 2)
	{
		if ((fd = ft_open(argv[1])) > 0)
		{
			tetris = ft_read_tetri(fd);
			t = ft_create_list(tetris);
			while (t[i])
			{
			printf("index : %d (%d, %d)\n", t[i]->index,t[i]->pos[0][0], t[i]->pos[0][1]);
			printf("index : %d (%d, %d)\n", t[i]->index,t[i]->pos[1][0], t[i]->pos[1][1]);
			printf("index : %d (%d, %d)\n", t[i]->index,t[i]->pos[2][0], t[i]->pos[2][1]);
			printf("index : %d (%d, %d)\n", t[i]->index,t[i]->pos[3][0], t[i]->pos[3][1]);
			printf("%s\n",t[i]->str);
			printf("W :%d / H : %d \n\n",t[i]->width, t[i]->height);
			i++;
			}
			map = ft_create_map(5);
			i = ft_place_piece(map, t[0], 0, 0);
			i = ft_place_piece(map, t[1], 2, 0);
			ft_print_map(5, map);
			ft_free_tab(map->map, 5);
			ft_memdel((void **)map);
		}
	}
	else
		ft_putstr("usage : fillit source_file\n");
	return (0);
}
