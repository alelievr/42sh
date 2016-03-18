/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:03:18 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/18 16:27:59 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strndup(const char *s1, size_t n)
{
	char				*dst;

	if (LIBFT_DEBUG && (s1 == NULL))
		ft_errnullptr("ft_strndup");
	dst = (char *)malloc((n + 1) * sizeof(char));
	if (dst != NULL)
		ft_strncpy(dst, s1, n);
	dst[n] = 0;
	return (dst);
}
