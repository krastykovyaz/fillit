/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:53:40 by ccharmai          #+#    #+#             */
/*   Updated: 2019/10/28 20:53:42 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_null(int *i, int *z, int *y)
{
	*i = 0;
	*z = 0;
	*y = 0;
}

char	**make_base(char *str)
{
	char	**out;
	int		i;
	int		z;
	int		y;

	set_null(&i, &z, &y);
	out = (char**)malloc(sizeof(char*) * 4);
	while (i < 4)
	{
		out[i] = (char*)malloc(sizeof(char) * 4);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		out[z][y] = str[i];
		y++;
		if (str[i] == '\n')
		{
			y = 0;
			z++;
		}
		i++;
	}
	return (out);
}
