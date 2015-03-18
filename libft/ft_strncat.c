/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:22:28 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:12:33 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strncat(char *s1, const char *s2, size_t n)
{
	char				*s;
	int					i;

	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strncat");
	i = 0;
	s = s1;
	while (*s)
		s++;
	while (s2[i] && (i < (int)n))
	{
		s[i] = s2[i];
		i++;
	}
	s[i + 1] = '\0';
	return (s1);
}
