/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:21:35 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/16 17:08:12 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list					*ft_lstnew(void const *content, size_t content_size)
{
	t_list				*link;
	int					i;

	link = (t_list *)malloc(sizeof(t_list));
	if (link == NULL)
		return (NULL);
	link->next = NULL;
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		link->content = malloc(content_size + 1);
		if (link->content == NULL)
			return (NULL);
		link->content_size = content_size;
		i = -1;
		while (++i < (int)content_size)
			((char *)(link->content))[i] = ((char *)content)[i];
	}
	return (link);
}
