/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:47:49 by ccharmai          #+#    #+#             */
/*   Updated: 2019/10/28 20:47:51 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check(char *t)
{
	int i;
	int j;

	i = -1;
	j = ft_strlen(t);
	if ((j + 1) % 21 != 0)
		return (0);
	while (t[++i])
	{
		if ((i + 1) % 21 == 0)
		{
			if (t[i] != '\n')
				return (0);
		}
		else if ((i - (i + 1) / 21 + 1) % 5 == 0)
		{
			if (t[i] != '\n')
				return (0);
		}
		else if (t[i] != '.' && t[i] != '#')
			return (0);
	}
	return (1);
}

int		helper(int connect)
{
	if (connect >= 6 && connect <= 10)
		return (1);
	return (0);
}

int		find_connect(char **base)
{
	int connect;
	int i;
	int z;

	connect = 0;
	i = 0;
	z = 0;
	while (z < 4)
	{
		while (i < 4)
		{
			if (i != 3 && base[z][i] == base[z][i + 1] && base[z][i] == '#')
				connect++;
			if (i != 0 && base[z][i] == base[z][i - 1] && base[z][i] == '#')
				connect++;
			if (z != 3 && base[z][i] == base[z + 1][i] && base[z][i] == '#')
				connect++;
			if (z != 0 && base[z][i] == base[z - 1][i] && base[z][i] == '#')
				connect++;
			i++;
		}
		i = 0;
		z++;
	}
	return (helper(connect));
}
