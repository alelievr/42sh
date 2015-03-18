/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:41:15 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:17:34 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strsub(const char *s, unsigned int start,
							size_t len)
{
	char				*str;
	int					i;

	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_strsub");
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	i = -1;
	while (++i < (int)len)
		str[i] = s[start + i];
	return (str);
}
