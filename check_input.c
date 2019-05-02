/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 09:42:28 by thallot           #+#    #+#             */
/*   Updated: 2019/05/02 11:07:49 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_connection(char *str)
{
	int connection;
	int i;

	i = 0;
	connection = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				connection++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				connection++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				connection++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				connection++;
		}
		i++;
	}
	if (connection == 6 || connection == 8)
		return (1);
	return (0);
}

int		ft_check_block(char *str, int last)
{
	int i;
	int nbr_block;
	int nbr_point;
	int nbr_nl;

	i = -1;
	nbr_nl = 0;
	nbr_point = 0;
	nbr_block = 0;
	if (!str)
		return (0);
	while (str[++i] != '\0')
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n' && str[i] != '\0')
			return (0);
		if ((i + 1) % 5 == 0 && str[i] != '\n')
			return (0);
		str[i] == '#' ? nbr_block++ : nbr_block;
		str[i] == '.' ? nbr_point++ : nbr_point;
		str[i] == '\n' ? nbr_nl++ : nbr_nl;
	}
	if ((nbr_block == 4 && nbr_point == 12)
		&& ((last == 0 && nbr_nl == 5) || (last == 1 && nbr_nl == 4)))
		return (1);
	return (0);
}
