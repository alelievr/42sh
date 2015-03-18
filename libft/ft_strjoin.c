/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:04:44 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:10:04 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strjoin(const char *s1, const char *s2)
{
	size_t				size1;
	size_t				size2;
	size_t				i;
	size_t				j;
	char				*dst;

	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strjoin");
	size1 = (s1 == NULL ? 0 : ft_strlen(s1));
	size2 = (s2 == NULL ? 0 : ft_strlen(s2));
	if ((dst = malloc((size1 + size2 + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s1 != NULL)
		while (i < size1)
			dst[j++] = s1[i++];
	i = 0;
	if (s2 != NULL)
		while (i < size2)
			dst[j++] = s2[i++];
	dst[size1 + size2] = '\0';
	return (dst);
}
