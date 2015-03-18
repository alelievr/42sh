/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 14:14:26 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/10 19:00:17 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix				*ft_mat_mul(t_matrix *m1, t_matrix *m2, t_matrix *res)
{
	static t_matrix		tmp;
	int					i;
	int					j;
	int					k;

	if (res == NULL)
		res = (t_matrix *)malloc(sizeof(t_matrix));
	i = -1;
	while ((++i < (int)m1->m) && (j = -1))
		while (++j < (int)m1->n)
		{
			tmp.tab[i][j] = 0;
			k = -1;
			while (++k < m1->n)
				tmp.tab[i][j] += m1->tab[i][k] * m2->tab[k][j];
		}
	i = -1;
	while ((++i < (int)m1->m) && (j = -1))
		while (++j < (int)m1->n)
			res->tab[i][j] = tmp.tab[i][j];
	res->m = m2->n;
	res->n = m1->m;
	return (res);
}
