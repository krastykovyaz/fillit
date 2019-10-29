/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:25:12 by lnoisome          #+#    #+#             */
/*   Updated: 2019/09/19 10:47:25 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (s1 && s2)
		len = (size_t)(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	else if (s1)
		len = (size_t)(ft_strlen((char*)s1));
	else if (s2)
		len = (size_t)(ft_strlen((char*)s2));
	else
		return (NULL);
	if (!(str = ft_memalloc(len)))
		return (NULL);
	if (s1)
		str = ft_strcpy(str, (char*)s1);
	else
		str = ft_strcpy(str, (char*)s2);
	if (s1 && s2)
		str = ft_strcat(str, (char*)s2);
	return (str);
}
