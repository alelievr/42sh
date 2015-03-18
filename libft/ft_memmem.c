/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 10:44:34 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 13:59:19 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmem(const void *big, size_t big_len,
							const void *little, size_t little_len)
{
	size_t				i;
	size_t				j;

	if (LIBFT_DEBUG && ((big == NULL) || (little == NULL)))
		ft_errnullptr("ft_memmem");
	i = 0;
	if ((big_len < little_len) || !big_len || !little_len)
		return (NULL);
	big_len -= little_len - 1;
	while (i < big_len)
	{
		j = 0;
		while (((char *)big)[i + j] == ((char *)little)[j])
		{
			if (j == little_len - 1)
				return ((void *)(((const char *)big) + i));
			++j;
		}
		++i;
	}
	return (NULL);
}
