/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:59:47 by lnoisome          #+#    #+#             */
/*   Updated: 2019/10/28 21:01:41 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		col_block(char *str)
{
	int	col;
	int	i;

	col = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			col++;
		i++;
	}
	if (i == 20)
		return (1);
	return (col);
}

char	**ft_slice(int col, char *str)
{
	char	**out;
	int		i;

	i = 0;
	out = (char **)malloc(sizeof(char *) * col);
	while (i < col)
	{
		out[i] = ft_strsub(str, i * 21, 20);
		i++;
	}
	return (out);
}

void	ft_out(void)
{
	int	g;
	int	z;

	g = 0;
	while (g < g_sizeside)
	{
		z = 0;
		while (z < g_sizeside)
		{
			ft_putchar(g_map[g][z] ? ('A' - 1 + g_map[g][z]) : '.');
			z++;
		}
		ft_putchar('\n');
		g++;
	}
}

void	null_matr(char ***mass2, int col)
{
	int	g;
	int	j;

	g_map = (int **)malloc(50 * sizeof(int *));
	g = -1;
	while (++g < 50)
	{
		g_map[g] = (int *)malloc(50 * sizeof(int));
		j = -1;
		while (++j < 50)
			g_map[g][j] = 0;
	}
	g_sizeside = 2;
	while (g_sizeside * g_sizeside < col * 4)
		g_sizeside++;
	while (g_sizeside <= 50)
	{
		if (solve(mass2, 1, col))
			break ;
		g_sizeside++;
	}
	ft_out();
	free_int_mass(&g_map, 50);
}

void	convert_main(char *str, int col)
{
	char	**mass;
	char	***mass2;
	int		f;
	int		z;

	mass = ft_slice(col, str);
	mass2 = malloc(sizeof(char *) * col);
	f = -1;
	while (++f < col)
		mass2[f] = make_base(mass[f]);
	z = -1;
	while (++z < col)
	{
		if (find_connect(mass2[z]) == 0)
		{
			ft_putstr("error\n");
			exit(0);
		}
	}
	f_move2(mass2, col);
	null_matr(mass2, col);
	free_mass(&mass, col);
	free_three_mass(mass2, col);
}
