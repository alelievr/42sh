/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:13:35 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 18:40:49 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int		init(int64_t nbr, t_pfflags *flags)
{
	return ((BIT_VAL(flags->flg, 13) ? MAX(flags->n_digits, flags->prec) :
	flags->n_digits) + ((nbr || BIT_VAL(flags->flg, 64))
	&& BIT_VAL(flags->flg, 5) ? T((flags->base == 8) ||
	(flags->base == 16), (flags->base == 8) +
	2 * (flags->base == 16), (flags->base > 9) + 2) : 0));
}

static inline void		write_format_pos(uint64_t nbr, t_pfflags *flags,
							char *buff, int *index)
{
	int					n;

	n = init(nbr, flags) - 1;
	if (!(flags->flg & 2))
		while (++n < flags->nformat)
			buff[++*index] = ' ';
	if ((nbr || BIT_VAL(flags->flg, 64)) && BIT_VAL(flags->flg, 5))
	{
		if ((flags->base == 8) || (flags->base == 16))
			buff[++*index] = '0';
		else
			write_base(buff, index, flags);
		if (flags->base == 16)
			buff[++*index] = (flags->flg & 1 ? 'X' : 'x');
	}
	if (flags->flg & 2)
		while (++n < flags->nformat)
			buff[++*index] = '0';
	write_uint(nbr, buff, flags, index);
}

static inline void		write_format_neg(uint64_t nbr, t_pfflags *flags,
							char *buff, int *index)
{
	int					n;

	n = init(nbr, flags) - 1;
	if ((nbr || BIT_VAL(flags->flg, 64)) && BIT_VAL(flags->flg, 5))
	{
		if ((flags->base == 8) || (flags->base == 16))
			buff[++*index] = '0';
		else
			write_base(buff, index, flags);
		if (flags->base == 16)
			buff[++*index] = (flags->flg & 1 ? 'X' : 'x');
	}
	write_uint(nbr, buff, flags, index);
	while (++n < flags->nformat)
		buff[++*index] = ' ';
}

int						format_uint(uint64_t nbr, t_pfflags *flags, char *buff)
{
	int					index;

	if ((flags->base < 2) || (flags->base > FTPF_MAXBASE))
		return (-1);
	if (BIT_VAL(flags->flg, 13))
		BIT_OFF(flags->flg, 2);
	index = -1;
	flags->n_digits = ft_ndigitsbase(nbr, (size_t)flags->base);
	if (BIT_VAL(flags->flg, 8))
		write_format_neg(nbr, flags, buff, &index);
	else
		write_format_pos(nbr, flags, buff, &index);
	return (index);
}
