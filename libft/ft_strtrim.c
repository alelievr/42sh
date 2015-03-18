/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:12:33 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:17:53 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		ft_strtrim_size(const char *s)
{
	int					size;

	size = -1;
	while (s[++size])
		;
	--size;
	while ((s[size] == ' ') || (s[size] == '\n') || (s[size] == '\t'))
		size--;
	return (size + 1);
}

char					*ft_strtrim(const char *s)
{
	int					i;
	int					size;
	char				*src;
	char				*dst;

	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_strtrim");
	src = (char *)s;
	while ((*src == ' ') || (*src == '\n') || (*src == '\t'))
		src++;
	if (!*src)
		return (ft_strnew(0));
	size = ft_strtrim_size(src);
	dst = malloc((size + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	dst[size] = '\0';
	i = -1;
	while (++i < size)
		dst[i] = src[i];
	return (dst);
}
