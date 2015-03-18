/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:28:10 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/02 19:32:50 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				len;
	char				*tmp;
	size_t				i;

	if (LIBFT_DEBUG && ((dst == NULL) || (src == NULL)))
		ft_errnullptr("ft_strlcat");
	len = ft_strlen(dst);
	tmp = dst + len;
	i = 0;
	while (src[i] && (len + i < size - 1))
	{
		tmp[i] = src[i];
		++i;
	}
	return (MIN(len, size) + ft_strlen(src));
}
