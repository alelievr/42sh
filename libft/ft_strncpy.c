/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:11:37 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/13 20:50:15 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strncpy(char *dst, const char *src, size_t n)
{
	int					i;

	if (LIBFT_DEBUG && ((dst == NULL) || (src == NULL)))
		ft_errnullptr("ft_strncpy");
	i = 0;
	while (src[i] && (i < (int)n))
	{
		dst[i] = src[i];
		i++;
	}
	i--;
	while (++i < (int)n)
		dst[i] = '\0';
	return (dst);
}
