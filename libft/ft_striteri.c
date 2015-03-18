/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:24:10 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:09:46 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int					i;

	if (LIBFT_DEBUG && ((s == NULL) || (f == NULL)))
		ft_errnullptr("ft_striteri");
	i = -1;
	while (s[++i])
		f((unsigned int)i, s + i);
}
