/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:03:14 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/02 19:33:23 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strrchr(char const *s, int c)
{
	char				*tmp;

	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_strrchr");
	tmp = (char *)s + ft_strlen(s) + 1;
	while (--tmp > s - 1)
		if (*tmp == (char)c)
			return (tmp);
	return (NULL);
}
