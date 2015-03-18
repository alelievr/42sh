/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:23:13 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 13:59:51 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memset(void *b, int c, size_t len)
{
	register int		i;

	if (LIBFT_DEBUG && (b == NULL))
		ft_errnullptr("ft_memset");
	i = -1;
	while (++i < (int)len)
		((char *)b)[i] = (char)(unsigned char)c;
	return (b);
}
