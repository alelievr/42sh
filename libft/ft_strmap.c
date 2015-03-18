/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:27:31 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:12:08 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strmap(char const *s, char (*f)(char))
{
	int					i;
	int					size;
	char				*dst;

	if (LIBFT_DEBUG && ((s == NULL) || (f == NULL)))
		ft_errnullptr("ft_strmap");
	size = -1;
	while (s[++size])
		;
	dst = (char *)malloc((size + 1) * sizeof(char));
	dst[size] = '\0';
	i = -1;
	while (++i < size)
		dst[i] = f(s[i]);
	return (dst);
}
