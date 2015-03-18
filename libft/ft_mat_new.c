/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 15:25:17 by fdaudre-          #+#    #+#             */
/*   Updated: 2014/12/26 16:27:43 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix				*ft_mat_new(unsigned char m, unsigned char n,
							double tab[FT_MAT_DIM][FT_MAT_DIM])
{
	t_matrix			*mat;
	int					i;
	int					j;

	mat = (t_matrix *)malloc(sizeof(t_matrix));
	mat->m = m;
	mat->n = n;
	i = -1;
	while (++i < (int)m)
	{
		j = -1;
		while (++j < (int)n)
			mat->tab[i][j] = tab[i][j];
	}
	return (mat);
}
