/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:23:27 by lnoisome          #+#    #+#             */
/*   Updated: 2019/09/19 10:47:25 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int		sp;
	int		sp_tmp;

	sp_tmp = 0;
	sp = 0;
	while (*s)
	{
		if (sp_tmp == 1 && *s == c)
			sp_tmp = 0;
		if (sp_tmp == 0 && *s != c)
		{
			sp_tmp = 1;
			sp++;
		}
		s++;
	}
	return (sp);
}

static void	delmen(char **a, int n)
{
	while (--n)
		free(a[n]);
	free(a);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		start;

	if (!s || !(tab = malloc((ft_count_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < ft_count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (!(tab[j] = ft_strsub(s, start, i - start)))
		{
			delmen(&tab[j], j);
			return (NULL);
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
