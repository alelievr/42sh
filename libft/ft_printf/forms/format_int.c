/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:13:12 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 18:39:48 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int		init(int64_t nbr, t_pfflags *flags)
{
	return ((BIT_VAL(flags->flg, 13) ? MAX(flags->n_digits, flags->prec) :
	flags->n_digits) + ((nbr < 0) || BIT_VAL(flags->flg, 3)
	|| BIT_VAL(flags->flg, 4) ? 1 : 0) +
	(nbr && BIT_VAL(flags->flg, 5) ? (flags->base > 9) + 2 : 0));
}

static inline void		write_format_pos(int64_t nbr, t_pfflags *flags,
							char *buff, int *index)
{
	int					n;

	n = init(nbr, flags) - 1;
	if (!BIT_VAL(flags->flg, 2))
		while ((int)++n < flags->nformat)
			buff[++*index] = ' ';
	if (nbr < 0)
		buff[++*index] = '-';
	else if (BIT_VAL(flags->flg, 3))
		buff[++*index] = '+';
	else if (BIT_VAL(flags->flg, 4))
		buff[++*index] = ' ';
	if (nbr && BIT_VAL(flags->flg, 5))
		write_base(buff, index, flags);
	if (BIT_VAL(flags->flg, 2))
		while (++n < flags->nformat)
			buff[++*index] = '0';
	write_uint((uint64_t)ABS(nbr), buff, flags, index);
}

static inline void		write_format_neg(int64_t nbr, t_pfflags *flags,
							char *buff, int *index)
{
	int					n;

	n = init(nbr, flags) - 1;
	if (nbr < 0)
		buff[++*index] = '-';
	else if (BIT_VAL(flags->flg, 3))
		buff[++*index] = '+';
	else if (BIT_VAL(flags->flg, 4))
		buff[++*index] = ' ';
	if (nbr && BIT_VAL(flags->flg, 5))
		write_base(buff, index, flags);
	write_uint((uint64_t)ABS(nbr), buff, flags, index);
	while (++n < flags->nformat)
		buff[++*index] = ' ';
}

int						format_int(int64_t nbr, t_pfflags *flags, char *buff)
{
	int					index;

	if ((flags->base < 2) || (flags->base > FTPF_MAXBASE))
		return (0);
	if (BIT_VAL(flags->flg, 13))
		BIT_OFF(flags->flg, 2);
	index = -1;
	flags->n_digits = ft_ndigitsbase((uint64_t)ABS(nbr), (size_t)flags->base);
	if (BIT_VAL(flags->flg, 8))
		write_format_neg(nbr, flags, buff, &index);
	else
		write_format_pos(nbr, flags, buff, &index);
	return (index);
}
