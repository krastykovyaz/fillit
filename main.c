/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:01:42 by ccharmai          #+#    #+#             */
/*   Updated: 2019/10/28 21:01:43 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char **av)
{
	int		i;
	int		col_fig;
	char	*str;
	int		col;
	int		col_2;

	str = rff(ac, av);
	col_fig = col_block(str);
	set_null(&col, &col_2, &i);
	while (str[i] != '\0')
	{
		(str[i] == '#') ? col++ : col_2++;
		i++;
	}
	if (col % 4 != 0 || col_2 == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
	if (ft_check(str) != 0)
		convert_main(str, col_fig);
	else
		ft_putstr("error\n");
	return (0);
}
