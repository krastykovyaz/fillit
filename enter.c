/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:57:47 by ccharmai          #+#    #+#             */
/*   Updated: 2019/10/28 20:57:48 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*rff(int ac, char **av)
{
	static char	buf[BUFF_SIZE];
	static char	*bufp = buf;
	static int	n;
	int			fd;

	n = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (n == 0)
		{
			n = read(fd, buf, sizeof(buf));
			bufp = buf;
		}
	}
	if (--n >= 0)
		bufp++;
	else
		EOF;
	return (buf);
	close(fd);
}
