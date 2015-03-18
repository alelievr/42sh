/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:53:47 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/02 17:34:12 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int					i;
	int					j;
	int					size_s1;
	int					size_s2;

	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strnstr");
	size_s1 = -1;
	size_s2 = -1;
	i = -1;
	if (!*s2)
		return ((char *)s1);
	while (s1[++size_s1])
		;
	while (s2[++size_s2])
		;
	while ((i++ < MIN(size_s1, (int)n) - size_s2) && ((j = 0) + 1))
		while (s1[i + j] == s2[j])
		{
			++j;
			if (!s2[j] || (j > (int)n))
				return ((char *)(s1 + i));
		}
	return (NULL);
}
