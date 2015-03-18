/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:03:58 by fdaudre-          #+#    #+#             */
/*   Updated: 2014/11/07 16:52:48 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_itoa_rec(long int nbr, char *s, int *index)
{
	if (nbr > 9)
		ft_itoa_rec(nbr / 10, s, index);
	s[(*index)++] = '0' + nbr % 10;
}

char					*ft_itoa(int n)
{
	char				*str;
	int					index;
	long int			nbr;

	str = malloc(12 * sizeof(*str));
	if (str == NULL)
		return (NULL);
	index = 0;
	nbr = (long int)n;
	if (nbr < 0)
	{
		str[index] = '-';
		index++;
	}
	ft_itoa_rec(ABS(nbr), str, &index);
	str[index] = '\0';
	return (str);
}
