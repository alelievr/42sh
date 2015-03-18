/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:03:43 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:36:44 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_lstiter(t_list *lst, void (*f)(t_list *link))
{
	t_list				*tmp;

	if (LIBFT_DEBUG && ((lst == NULL) || (f == NULL)))
		ft_errnullptr("ft_lstiter");
	while (lst != NULL)
	{
		tmp = lst->next;
		f(lst);
		lst = tmp;
	}
}
