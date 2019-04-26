/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:14:31 by thallot           #+#    #+#             */
/*   Updated: 2019/04/26 13:17:58 by thallot          ###   ########.fr       */
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
	ft_memdel((void **)map);
}
