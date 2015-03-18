/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 14:14:05 by fdaudre-          #+#    #+#             */
/*   Updated: 2014/12/26 15:51:39 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix				*ft_mat_sub(t_matrix *m1, t_matrix *m2, t_matrix *res)
{
	int					i;
	int					j;

	if (res == NULL)
		res = (t_matrix *)malloc(sizeof(t_matrix));
	i = -1;
	while (++i < (int)m1->m)
	{
		j = -1;
		while (++j < (int)m1->n)
			res->tab[i][j] = m1->tab[i][j] - m2->tab[i][j];
	}
	res->m = m1->m;
	res->n = m1->n;
	return (res);
}
