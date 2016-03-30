/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 12:05:21 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/27 19:15:53 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		ft_strsplit_nbr(char const *s, char const *c)
{
	int			ret;

	ret = 0;
	while (*s)
	{
		while (ft_strchr(c, *s) && *s)
			s++;
		if (!*s)
			break ;
		while (!ft_strchr(c, *s) && *s)
			s++;
		ret++;
	}
	return (ret);
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
	if (!(tab = (char **)malloc((nbr + 1) * sizeof(*tab))))
		return (NULL);
	tab[nbr] = NULL;
	ft_strsplit_write(tab, s, c);
	return (tab);
}
