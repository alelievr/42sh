/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 22:32:04 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:38:21 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				ft_lstsort_swap(t_list *l1, t_list *l2)
{
	void				*tmp;
	size_t				size;

	tmp = l1->content;
	l1->content = l2->content;
	l2->content = tmp;
	size = l1->content_size;
	l1->content_size = l2->content_size;
	l2->content_size = size;
}

static inline t_list	*ft_lstsort_sorting(t_list *low, t_list *high,
							int (*f)(const void *, const void *))
{
	t_list				*tmp;
	t_list				*arrow;
	void				*median;

	tmp = low->next;
	arrow = low;
	median = low->content;
	while (tmp != high)
	{
		if (f((char *)tmp->content, (char *)median) < 0)
		{
			arrow = arrow->next;
			ft_lstsort_swap(tmp, arrow);
		}
		tmp = tmp->next;
	}
	ft_lstsort_swap(low, arrow);
	return (arrow);
}

static void				ft_lstsort_rec(t_list *low, t_list *high,
							int (*f)(const void *, const void *))
{
	t_list				*median;

	if (high == low)
		return ;
	median = ft_lstsort_sorting(low, high, f);
	ft_lstsort_rec(low, median, f);
	ft_lstsort_rec(median->next, high, f);
}

void					ft_lstsort(t_list *lst,
							int (*f)(const void *, const void *))
{
	if (LIBFT_DEBUG && ((lst == NULL) || (f == NULL)))
		ft_errnullptr("ft_lstsort");
	ft_lstsort_rec(lst, NULL, f);
}
