/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:37:32 by thallot           #+#    #+#             */
/*   Updated: 2019/04/26 13:44:29 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct	s_map
{
	int		size;
	char	**map;
}				t_map;

typedef struct	s_tetri
{
	int		index;
	int		pos[4][2];
	int		width;
	int		height;
	char	*str;
}				t_tetri;

void	ft_freetab(char **tab);
int		ft_open(char *file);
int		ft_check_connection(char *str);
int		ft_check_block(char *str);
int		*ft_get_size(char *str);

char	**ft_read_tetri(int fd);
char	*ft_place_min(char *str, int min_x, int min_y);
char	*ft_change_char(char *str, char c);

t_tetri	*ft_create_tetri(char *str, int index);
t_tetri	**ft_create_list(char **tetris);

t_map	*ft_create_map(int size);
int		ft_place_piece(t_map *map, t_tetri *tetri, int x, int y);

void	ft_print_map(int size, t_map *map);
void	ft_free_tab(char **map, int size);

#endif
