/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 12:05:21 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/20 12:05:27 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		ft_strsplit_nbr(char const *s, char const *c)
{
	int					i;
	int					nbr;
	int					last;

	i = -1;
	last = 1;
	nbr = 1;
	while (s[++i])
		if (ft_strchr(c, s[i]) != NULL)
		{
			if (!last)
				nbr++;
			if (!s[i + 1])
				nbr--;
			last = 1;
		}
		else
			last = 0;
	return (nbr);
}

void					ft_strsplit_write(char **tab,
							char const *s, char const *c)
{
	int					index;
	size_t				size;

	index = -1;
	while (*s)
	{
		if (ft_strchr(c, *s) == NULL)
		{
			size = 0;
			while (s[++size] && (ft_strchr(c, s[size]) == NULL))
				;
			tab[++index] = (char *)malloc((size + 1) * sizeof(char));
			ft_strncpy(tab[index], s, size);
			tab[index][size] = '\0';
			s += size;
		}
		else
			++s;
	}
}

char					**ft_strsplit(char const *s, char const *c)
{
	char				**tab;
	int					nbr;

	nbr = ft_strsplit_nbr(s, c);
	tab = (char **)malloc((nbr + 1) * sizeof(*tab));
	tab[nbr] = NULL;
	ft_strsplit_write(tab, s, c);
	return (tab);
}
