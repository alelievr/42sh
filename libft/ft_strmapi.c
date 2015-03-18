/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:36:00 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:12:20 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strmapi(char const *s, char (*f)(unsigned int,
							char))
{
	int					i;
	int					size;
	char				*dst;

	if (LIBFT_DEBUG && ((s == NULL) || (f == NULL)))
		ft_errnullptr("ft_strmapi");
	size = -1;
	while (s[++size])
		;
	dst = malloc((size + 1) * sizeof(char));
	dst[size] = '\0';
	i = -1;
	while (++i < size)
		dst[i] = f((unsigned int)i, s[i]);
	return (dst);
}
