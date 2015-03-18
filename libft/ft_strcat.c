/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:21:52 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:00:31 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strcat(char *s1, const char *s2)
{
	char				*s;
	int					i;

	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strcat");
	i = -1;
	s = s1;
	while (*s)
		s++;
	while (s2[++i])
		s[i] = s2[i];
	s[i] = '\0';
	return (s1);
}
