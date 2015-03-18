/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 12:20:35 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:21:50 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_prec(t_pfflags *flags, const char *format,
							va_list ap)
{
	BIT_ON(flags->flg, 13);
	if (format[1] == '*')
	{
		flags->prec = va_arg(ap, int);
		if (flags->prec < 0)
			BIT_OFF(flags->flg, 13);
		return (2);
	}
	flags->prec = atoi(format + 1);
	return (ft_nbrlen((int64_t)flags->prec, 10) +
	((format[1] < '0') || (format[1] > '9') ? 0 : 1));
}
