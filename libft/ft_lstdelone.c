/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:51:02 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:36:22 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_lstdelone(t_list **link, void (*del)(void *, size_t))
{
	if (LIBFT_DEBUG && ((link == NULL) || (del == NULL)))
		ft_errnullptr("ft_lstdelone");
	del((*link)->content, (*link)->content_size);
	free(*link);
	*link = NULL;
}
