/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:20:07 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:17:17 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strstr(const char *s1, const char *s2)
{
	int					i;
	int					j;
	int					size_s1;
	int					size_s2;

	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strstr");
	size_s1 = -1;
	size_s2 = -1;
	i = -1;
	if (!*s2)
		return ((char *)s1);
	while (s1[++size_s1])
		;
	while (s2[++size_s2])
		;
	while ((i++ < size_s1 - size_s2) && ((j = 0) + 1))
		while (s1[i + j] == s2[j])
		{
			j++;
			if (!s2[j])
				return ((char *)(s1 + i));
		}
	return (NULL);
}
