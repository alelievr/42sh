/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:23:51 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:35:39 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_lstback(t_list *link, t_list *new)
{
	if (LIBFT_DEBUG && ((link == NULL) || (new == NULL)))
		ft_errnullptr("ft_lstback");
	while (link->next != NULL)
		link = link->next;
	link->next = new;
}
