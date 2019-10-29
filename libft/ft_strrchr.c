/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:20:20 by lnoisome          #+#    #+#             */
/*   Updated: 2019/09/12 22:58:02 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (0);
	while (*s != '\0')
	{
		if (*s == c)
			ptr = ((char *)s);
		s++;
	}
	if (ptr != '\0')
		return (ptr);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
