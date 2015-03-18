/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:42:55 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:34:36 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_lstadd(t_list **link, t_list *new)
{
	if (LIBFT_DEBUG && ((new == NULL) || (link == NULL)))
		ft_errnullptr("ft_lstadd");
	new->next = *link;
	*link = new;
}
