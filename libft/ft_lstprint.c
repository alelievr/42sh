/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 17:25:33 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:37:58 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_lstprint(const t_list *lst,
							void (*f)(const void *, size_t))
{
	if (LIBFT_DEBUG && ((lst == NULL) || (f == NULL)))
		ft_errnullptr("ft_lstprint");
	while (lst != NULL)
	{
		ft_putstr("[\033[31m\033[1m");
		f(lst->content, lst->content_size);
		ft_putstr("\033[0m]->");
		lst = lst->next;
	}
	ft_putstr("\033[31m\033[1mNULL\033[0m\n");
}
