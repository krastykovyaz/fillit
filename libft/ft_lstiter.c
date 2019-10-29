/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:54:20 by lnoisome          #+#    #+#             */
/*   Updated: 2019/09/12 20:58:53 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (f)(t_list *elem))
{
	t_list *ptr;

	if (lst)
	{
		ptr = lst;
		while (ptr)
		{
			f(ptr);
			ptr = ptr->next;
		}
	}
}
