/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:35:35 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:02:30 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strdup(const char *s1)
{
	char				*dst;

	if (LIBFT_DEBUG && (s1 == NULL))
		ft_errnullptr("ft_strdup");
	dst = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dst != NULL)
		ft_strcpy(dst, s1);
	return (dst);
}
