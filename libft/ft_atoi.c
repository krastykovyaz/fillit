/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 09:52:18 by lnoisome          #+#    #+#             */
/*   Updated: 2019/09/19 10:47:25 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*f(const char *s)
{
	const char	*res;

	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\f' ||
			*s == '\r' || *s == '\v')
	{
		s++;
	}
	res = s;
	return (res);
}

static int			chsize(unsigned long long n, const char *s, int sign)
{
	n = n * 10 + (*s - '0');
	if (n > MAXLL && sign == -1)
		return (0);
	else if (n > MAXLL && sign == 1)
		return (-1);
	return (1);
}

int					ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;
	const char			*ptr;
	int					size;

	num = 0;
	ptr = f(str);
	sign = (*ptr == '-') * -2 + 1;
	if (*ptr == '-')
		ptr++;
	else if (*ptr == '+')
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
	{
		size = chsize(num, ptr, sign);
		if (size == 0 || size == -1)
			return (size);
		num = num * 10 + *ptr++ - '0';
	}
	return (num * sign);
}
