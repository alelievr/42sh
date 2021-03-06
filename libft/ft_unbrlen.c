/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 15:20:38 by fdaudre-          #+#    #+#             */
/*   Updated: 2014/12/30 15:21:10 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_unbrlen(uint64_t nbr, const size_t base)
{
	int					n;

	n = 1;
	while (nbr /= (int)base)
		++n;
	return (n);
}
