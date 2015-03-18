/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:26:26 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:39:10 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memalloc(size_t size)
{
	void				*mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	return (ft_memset(mem, 0, size));
}
