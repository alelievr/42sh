/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:14:22 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:16:21 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		ft_strsplit_nbr(const char *s, char c)
{
	int					i;
	int					nbr;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			nbr++;
		while ((s[i] != c) && s[i])
			i++;
	}
	return (nbr);
}

static int				ft_strsplit_write(const char *src, char **dst, char c)
{
	int					i;
	int					size;

	size = 0;
	while ((src[size] != c) && src[size])
		size++;
	*dst = (char *)malloc((size + 1) * sizeof(**dst));
	if (*dst == NULL)
		return (-1);
	(*dst)[size] = '\0';
	i = -1;
	while (++i < size)
		(*dst)[i] = src[i];
	return (i);
}

char					**ft_strsplit(const char *s, char c)
{
	char				**tab;
	int					nbr;
	int					i;
	int					n;
	int					index;

	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_strsplit");
	nbr = ft_strsplit_nbr(s, c);
	tab = (char **)malloc((nbr + 1) * sizeof(*tab));
	if (tab == NULL)
		return (NULL);
	tab[nbr] = '\0';
	index = -1;
	i = 0;
	while (++index < nbr)
	{
		while (s[i] == c)
			++i;
		n = ft_strsplit_write(s + i, &(tab[index]), c);
		if (n < 0)
			return (NULL);
		i += n;
	}
	return (tab);
}
