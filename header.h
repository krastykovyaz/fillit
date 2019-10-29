/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:59:40 by ccharmai          #+#    #+#             */
/*   Updated: 2019/10/28 20:59:42 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include "libft/libft.h"

int		**g_map;

int		g_sizeside;
char	*rff(int ac, char **av);
char	**make_base(char *str);
int		find_connect(char **base);
int		col_block(char *str);
int		ft_check(char *t);
void	convert_main(char *str, int col_fig);
int		solve(char ***mass2, int a, int col);
void	f_move2(char ***mass2, int col);
void	free_int_mass(int ***mas, int len);
void	free_mass(char ***mas, int len);
void	free_three_mass(char ***mas, int col);
void	set_null(int *i, int *z, int *y);

#endif
