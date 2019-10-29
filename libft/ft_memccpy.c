/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:09:24 by lnoisome          #+#    #+#             */
/*   Updated: 2019/09/19 10:47:25 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	*s1;
	unsigned char	cc;

	i = 0;
	cc = c;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		s1[i] = s2[i];
		if (s1[i] == cc)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
