/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:31:26 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:36:02 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_lstdel(t_list **link, void (*del)(void *, size_t))
{
	t_list				*tmp;

	if (LIBFT_DEBUG && ((link == NULL) || (del == NULL)))
		ft_errnullptr("ft_lstdel");
	while (*link != NULL)
	{
		tmp = (*link)->next;
		ft_lstdelone(link, del);
		*link = tmp;
	}
}
