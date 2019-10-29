/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:45:10 by lnoisome          #+#    #+#             */
/*   Updated: 2019/09/12 22:29:41 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr;

	ptr = (const unsigned char*)s;
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void*)ptr);
		n--;
		ptr++;
	}
	return (0);
}
