/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:41:14 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 17:30:37 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void		write_rec(uint64_t nbr, char *buff, t_pfflags *flags,
							int *index)
{
	if (nbr > (size_t)(flags->base - 1))
		write_rec(nbr / flags->base, buff, flags, index);
	if (nbr % flags->base < 10)
		buff[++*index] = '0' + nbr % flags->base;
	else
		buff[++*index] = (BIT_VAL(flags->flg, 1) ? 'A' : 'a') + nbr %
			flags->base - 10;
}

inline void				write_uint(uint64_t nbr, char *buff, t_pfflags *flags,
							int *index)
{
	int					n;

	if (BIT_VAL(flags->flg, 13))
	{
		n = flags->n_digits - 1;
		while (++n < flags->prec)
			buff[++*index] = '0';
	}
	write_rec(nbr, buff, flags, index);
}

inline void				write_base(char *buff, int *index, t_pfflags *flags)
{
	if (flags->base > 9)
		buff[++*index] = '0' + flags->base / 10;
	buff[++*index] = '0' + flags->base % 10;
	buff[++*index] = (BIT_VAL(flags->flg, 1) ? 'B' : 'b');
}
