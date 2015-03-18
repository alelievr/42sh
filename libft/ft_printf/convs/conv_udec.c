/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_udec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:54:25 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/15 15:57:25 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				conv_lludec(va_list ap, t_pfflags *flags, char *buff)
{
	unsigned long long int	nbr;

	nbr = va_arg(ap, unsigned long long int);
	return (format_uint((uint64_t)nbr, flags, buff));
}

int						conv_ludec(va_list ap, t_pfflags *flags, char *buff)
{
	unsigned long int	nbr;

	if (BIT_VAL(flags->flg, 7) || BIT_VAL(flags->flg, 12)
			|| BIT_VAL(flags->flg, 11))
		return (conv_lludec(ap, flags, buff));
	nbr = va_arg(ap, unsigned long int);
	return (format_uint((uint64_t)nbr, flags, buff));
}

static int				conv_hhudec(va_list ap, t_pfflags *flags, char *buff)
{
	unsigned char		nbr;

	nbr = (unsigned char)va_arg(ap, int);
	return (format_uint((uint64_t)nbr, flags, buff));
}

static int				conv_hudec(va_list ap, t_pfflags *flags, char *buff)
{
	short unsigned int	nbr;

	if (BIT_VAL(flags->flg, 10))
		return (conv_hhudec(ap, flags, buff));
	nbr = (short unsigned int)va_arg(ap, int);
	return (format_uint((uint64_t)nbr, flags, buff));
}

int						conv_udec(va_list ap, t_pfflags *flags, char *buff)
{
	unsigned int		nbr;

	if (BIT_VAL(flags->flg, 12) || BIT_VAL(flags->flg, 11))
		return (conv_lludec(ap, flags, buff));
	if (BIT_VAL(flags->flg, 6))
		return (conv_ludec(ap, flags, buff));
	if (BIT_VAL(flags->flg, 9))
		return (conv_hudec(ap, flags, buff));
	nbr = va_arg(ap, unsigned int);
	return (format_uint((uint64_t)nbr, flags, buff));
}
