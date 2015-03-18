/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:38:23 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/02 17:09:38 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t				i;

	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strnequ");
	if (!n)
		return (1);
	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && (i < n - 1))
		i++;
	return (s1[i] == s2[i] ? 1 : 0);
}
