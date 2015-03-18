/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:28:51 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/02 20:38:26 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONGPTR_MASK	(sizeof(uint64_t) - 1)

#define MASK01			0x0101010101010101
#define MASK80			0x8080808080808080

static inline size_t	testbytes(const char *str, char *p)
{
	if (!p[0])
		return (p - str);
	else if (!p[1])
		return (p - str + 1);
	else if (!p[2])
		return (p - str + 2);
	else if (!p[3])
		return (p - str + 3);
	else if (!p[4])
		return (p - str + 4);
	else if (!p[5])
		return (p - str + 5);
	else if (!p[6])
		return (p - str + 6);
	return (p - str + 7);
}

size_t					ft_strlen(register const char *str)
{
	register char			*p;
	register uint64_t		*lp;

	if (LIBFT_DEBUG && (str == NULL))
		ft_errnullptr("ft_strlen");
	p = (char *)str;
	while ((uint64_t)p & LONGPTR_MASK)
	{
		if (!*p)
			return (p - str);
		p++;
	}
	lp = (uint64_t *)p;
	while (42)
	{
		if ((*lp - MASK01) & MASK80)
			break ;
		lp++;
	}
	return (testbytes(str, (char *)lp));
}
