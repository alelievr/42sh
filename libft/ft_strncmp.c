/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:21:22 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/05 20:53:45 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;

	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strncmp");
	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && (i < n - 1))
		i++;
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}
