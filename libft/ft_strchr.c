/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:59:52 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:00:52 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONGPTR_MASK	(sizeof(uint64_t) - 1)
#define MAGIC_PTR		(char *)0x1

static inline char		*testbytes_ftn(char *p, const char ch)
{
	if (*++p == ch)
		return ((char *)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)p);
	else if (!*p)
		return (NULL);
	return (MAGIC_PTR);
}

static inline char		*testbytes(char *p, const char ch)
{
	if (*p == ch)
		return ((char *)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)p);
	else if (!*p)
		return (NULL);
	return (testbytes_ftn(p, ch));
}

static inline char		*ft_strchr_ftn(const char *s, const unsigned char ch)
{
	uint64_t				charmask;
	static const uint64_t	mask = 0x7efefefefefefeff;
	register uint64_t		*lp;
	char					*nique_la_norme;

	lp = (uint64_t *)s;
	charmask = ch | (ch << 8);
	charmask |= charmask << 16;
	charmask |= charmask << 32;
	while (42)
	{
		if ((((*lp + mask) ^ ~*lp) & ~mask)
				|| ((((*lp ^ charmask) + mask) ^ ~(*lp ^ charmask)) & ~mask))
		{
			if ((nique_la_norme = testbytes((char *)lp, ch)) != MAGIC_PTR)
				return (nique_la_norme);
		}
		lp++;
	}
	return (NULL);
}

char					*ft_strchr(const char *s, int c)
{
	register char		*p;

	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_strchr");
	p = (char *)s;
	while ((uint64_t)p & LONGPTR_MASK)
	{
		if (*p == (char)c)
			return (p);
		else if (!*p)
			return (NULL);
		p++;
	}
	return (ft_strchr_ftn(p, (unsigned char)c));
}
