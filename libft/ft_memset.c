/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:57:17 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/08 15:51:29 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#define OPSIZE		(sizeof(t_op))
#define MEM_FILL(x, y) x[0]=y;x[1]=y;x[2]=y;x[3]=y;x[4]=y;x[5]=y;x[6]=y;x[7]=y

static inline void	ft_memset_align64_(long *dstp, size_t *len, int c)
{
	while ((*dstp) % OPSIZE != 0)
	{
		((unsigned char *)(*dstp))[0] = c;
		(*dstp)++;
		(*len)--;
	}
}

static inline void	ft_memset_last_bytes_(size_t *len, long *dstp,
		const t_op cccc)
{
	size_t	xlen;

	xlen = (*len) / OPSIZE + 1;
	while (--xlen > 0)
	{
		((t_op *)(*dstp))[0] = cccc;
		*dstp += OPSIZE;
	}
	*len %= OPSIZE;
}

void				*ft_memset(void *b, int c, size_t len)
{
	long				dstp;
	register size_t		xlen;
	t_op				cccc;

	dstp = (long)b;
	if (len >= 8)
	{
		cccc = (unsigned char)c;
		cccc |= cccc << 8;
		cccc |= cccc << 16;
		if (sizeof(t_op) > 4)
			cccc |= cccc << 32;
		ft_memset_align64_(&dstp, &len, c);
		xlen = len / (OPSIZE * 8) + 1;
		while (--xlen > 0)
		{
			MEM_FILL(((t_op *)dstp), cccc);
			dstp += 8 * OPSIZE;
		}
		len %= OPSIZE * 8;
		ft_memset_last_bytes_(&len, &dstp, cccc);
	}
	while (len-- > 0)
		((unsigned char *)dstp++)[0] = c;
	return (b);
}
