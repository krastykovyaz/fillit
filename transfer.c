/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:50:51 by ccharmai          #+#    #+#             */
/*   Updated: 2019/10/28 20:50:52 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set1(char ***mass2, int i1)
{
	int i3;
	int i4;

	if (mass2[i1][0][0] == '.' && mass2[i1][0][1] == '.' \
	&& mass2[i1][0][2] == '.' && mass2[i1][0][3] == '.')
	{
		i3 = -1;
		while (++i3 < 3)
		{
			i4 = -1;
			while (++i4 < 4)
				ft_swap(&mass2[i1][i3][i4], &mass2[i1][i3 + 1][i4]);
		}
	}
}

void	f_move2(char ***mass2, int col)
{
	int i3;
	int i4;
	int i1;
	int i2;

	i1 = -1;
	while (++i1 < col)
	{
		i2 = -1;
		while (++i2 < 3)
		{
			set1(mass2, i1);
			if (mass2[i1][0][0] == '.' && mass2[i1][1][0] == '.' \
			&& mass2[i1][2][0] == '.' && mass2[i1][3][0] == '.')
			{
				i4 = -1;
				while (++i4 < 3)
				{
					i3 = -1;
					while (++i3 < 4)
						ft_swap(&mass2[i1][i3][i4], &mass2[i1][i3][i4 + 1]);
				}
			}
		}
	}
}
