/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:17:46 by thallot           #+#    #+#             */
/*   Updated: 2019/06/03 10:36:46 by thallot          ###   ########.fr       */
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

void	*ft_free_read(char **tetris, char *buffer, int nb_tetris)
{
	ft_memdel((void**)tetris);
	ft_memdel((void **)&buffer);
	ft_free_tab(tetris, nb_tetris);
	return (NULL);
}

char	**ft_read_tetri(int fd)
{
	char	**tetris;
	char	*buffer;
	int		cursor;
	int		nb_tetris;
	int		tmp;

	nb_tetris = 0;
	if (!(tetris = (char **)ft_memalloc(sizeof(char *) * 27)))
		return (NULL);
	buffer = ft_strnew(21);
	while ((cursor = read(fd, buffer, 21)))
	{
		if (!ft_check_connection(buffer) || !ft_check_block(buffer,
			cursor == 21 ? 0 : 1) || nb_tetris > 25)
			return (ft_free_read(tetris, buffer, nb_tetris));
		buffer[cursor] = '\0';
		tetris[nb_tetris++] = ft_strndup(buffer, 21);
		ft_bzero(buffer, 21);
		tmp = cursor;
	}
	if (tmp != 20)
		return (ft_free_read(tetris, buffer, nb_tetris));
	ft_memdel((void **)&buffer);
	close(fd);
	return (tetris);
}
