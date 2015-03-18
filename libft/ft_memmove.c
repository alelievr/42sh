/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:39:39 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 13:59:36 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)

{
	register int		i;

	if (LIBFT_DEBUG && ((dst == NULL) || (src == NULL)))
		ft_errnullptr("ft_memmove");
	if ((long int)dst > (long int)src)
	{
		i = (int)len;
		while (--i > -1)
			((char *)dst)[i] = ((char *)src)[i];
	}
	else
	{
		i = -1;
		while (++i < (int)len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
