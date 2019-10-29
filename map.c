/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:55:18 by ccharmai          #+#    #+#             */
/*   Updated: 2019/10/28 20:55:20 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		findloc(char **mass2, int x, int y, int a)
{
	int k;
	int m;

	k = -1;
	while (++k < 4)
	{
		m = -1;
		while (++m < 4)
		{
			if (mass2[k][m] == '#')
			{
				if (k + y >= g_sizeside || m + x >= g_sizeside ||
				g_map[k + y][m + x])
					return (1);
				g_map[k + y][m + x] = a;
			}
		}
	}
	return (0);
}

void	delloc(int x, int y, int a)
{
	int k;
	int m;

	k = 0;
	while (k < 4)
	{
		m = 0;
		while (m < 4)
		{
			if (k + y < g_sizeside && m + x < g_sizeside &&
			g_map[k + y][m + x] == a)
				g_map[k + y][m + x] = 0;
			m++;
		}
		k++;
	}
}

int		solve(char ***mass2, int a, int col)
{
	int k;
	int m;

	if (a > col)
		return (1);
	k = -1;
	while (++k < g_sizeside)
	{
		m = -1;
		while (++m < g_sizeside)
		{
			if (findloc(mass2[a - 1], m, k, a))
			{
				delloc(m, k, a);
				continue;
			}
			if (solve(mass2, a + 1, col))
				return (1);
			else
				delloc(m, k, a);
		}
	}
	return (0);
}
