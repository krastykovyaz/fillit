/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:37:10 by lnoisome          #+#    #+#             */
/*   Updated: 2019/09/19 10:47:25 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	isneg(int *nb, int *neg)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*neg = 1;
	}
}

char		*ft_itoa(int nb)
{
	int		size;
	int		negative;
	char	*str;
	int		n;

	negative = 0;
	size = 2;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	n = nb;
	isneg(&nb, &negative);
	while (n /= 10)
		size++;
	size += negative;
	if ((str = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	str[--size] = '\0';
	while (size--)
	{
		str[size] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
