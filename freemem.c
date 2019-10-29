/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:44:56 by ccharmai          #+#    #+#             */
/*   Updated: 2019/10/28 20:44:58 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_mass(char ***mas, int len)
{
	int z;

	z = -1;
	while (++z < len)
		free((*mas)[z]);
	free(*mas);
}

void	free_int_mass(int ***mas, int len)
{
	int z;

	z = -1;
	while (++z < len)
		free((*mas)[z]);
	free(*mas);
}

void	free_three_mass(char ***mas, int col)
{
	int z;
	int i;

	z = -1;
	while (++z < col)
	{
		i = -1;
		while (++i < 4)
			free(mas[z][i]);
		free(mas[z]);
	}
	free(mas);
}
