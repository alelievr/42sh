/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:20:22 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:08:48 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_strequ(const char *s1, const char *s2)
{
	int					i;

	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strequ");
	i = 0;
	while ((s1[i] == s2[i]) && s1[i])
		i++;
	return (s1[i] == s2[i] ? 1 : 0);
}
