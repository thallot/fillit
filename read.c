/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:17:46 by thallot           #+#    #+#             */
/*   Updated: 2019/04/30 15:25:47 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_open(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd > 0)
		return (fd);
	return (0);
}

char	**ft_read_tetri(int fd)
{
	char	**tetris;
	char	*buffer;
	int		cursor;
	int		nb_tetris;

	nb_tetris = 0;
	if (!(tetris = (char **)ft_memalloc(sizeof(char *) * 27)))
		return (NULL);
	buffer = ft_strnew(21);
	while ((cursor = read(fd, buffer, 21)) >= 20)
	{
		if (!ft_check_connection(buffer) || !ft_check_block(buffer))
		{
			ft_memdel((void**)tetris);
			ft_memdel((void **)&buffer);
			ft_free_tab(tetris, nb_tetris);
			return (NULL);
		}
		buffer[cursor] = '\0';
		tetris[nb_tetris++] = ft_strndup(buffer, 20);
	}
	ft_memdel((void **)&buffer);
	close(fd);
	return (tetris);
}
