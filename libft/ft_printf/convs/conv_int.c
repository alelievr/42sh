/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 20:12:19 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/15 15:56:50 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				conv_llint(va_list ap, t_pfflags *flags, char *buff)
{
	long long int		nbr;

	nbr = va_arg(ap, long long int);
	return (format_int((int64_t)nbr, flags, buff));
}

int						conv_lint(va_list ap, t_pfflags *flags, char *buff)
{
	long int			nbr;

	if (BIT_VAL(flags->flg, 7) || BIT_VAL(flags->flg, 12)
			|| BIT_VAL(flags->flg, 11))
		return (conv_llint(ap, flags, buff));
	nbr = va_arg(ap, long int);
	return (format_int((int64_t)nbr, flags, buff));
}

static int				conv_hhint(va_list ap, t_pfflags *flags, char *buff)
{
	char				nbr;

	nbr = (char)va_arg(ap, int);
	return (format_int((int64_t)nbr, flags, buff));
}

static int				conv_hint(va_list ap, t_pfflags *flags, char *buff)
{
	short int			nbr;

	if (BIT_VAL(flags->flg, 10))
		return (conv_hhint(ap, flags, buff));
	nbr = (short int)va_arg(ap, int);
	return (format_int((int64_t)nbr, flags, buff));
}

int						conv_int(va_list ap, t_pfflags *flags, char *buff)
{
	int					nbr;

	if (BIT_VAL(flags->flg, 12) || BIT_VAL(flags->flg, 11))
		return (conv_llint(ap, flags, buff));
	if (BIT_VAL(flags->flg, 6))
		return (conv_lint(ap, flags, buff));
	if (BIT_VAL(flags->flg, 9))
		return (conv_hint(ap, flags, buff));
	nbr = va_arg(ap, int);
	return (format_int((int64_t)nbr, flags, buff));
}
