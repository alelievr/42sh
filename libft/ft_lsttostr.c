/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:04:36 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:38:43 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		ft_lsttostr_nbr(t_list *lst)
{
	size_t				nbr;

	nbr = 0;
	while (lst != NULL)
	{
		nbr += lst->content_size;
		lst = lst->next;
	}
	return (nbr + 1);
}

char					*ft_lsttostr(t_list *lst)
{
	int					i;
	int					nbr;
	char				*str;

	if (LIBFT_DEBUG && (lst == NULL))
		ft_errnullptr("ft_lsttostr");
	str = (char *)malloc(ft_lsttostr_nbr(lst) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	nbr = -1;
	while (lst != NULL)
	{
		i = -1;
		if (lst->content != NULL)
			while (++i < (int)lst->content_size)
				str[++nbr] = ((char *)lst->content)[i];
		lst = lst->next;
	}
	str[nbr + 1] = '\0';
	return (str);
}
