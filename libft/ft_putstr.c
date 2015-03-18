/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:03:17 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/18 17:17:10 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_putstr(const char *s)
{
	int					size;

	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_putstr");
	size = -1;
	while (s[++size])
		;
	write(1, s, size);
}
