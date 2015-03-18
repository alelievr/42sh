/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:20:38 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:37:13 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *link))
{
	t_list				*i;
	t_list				*new;
	t_list				*tmp;

	if (LIBFT_DEBUG && ((lst == NULL) || (f == NULL)))
		ft_errnullptr("ft_lstmap");
	new = f(lst);
	if (new == NULL)
		return (NULL);
	lst = lst->next;
	tmp = new;
	while (lst != NULL)
	{
		i = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		lst = i;
	}
	return (new);
}
