/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 13:11:24 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/19 13:43:03 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_base(t_pfflags *flags, const char *format,
							va_list ap)
{
	flags->base = ft_atoi(format + 1);
	return (ft_nbrlen((int64_t)flags->base, 10) + 1);
	(void)ap;
}

int						flag_basemaj(t_pfflags *flags, const char *format,
							va_list ap)
{
	BIT_ON(flags->flg, 1);
	return (flag_base(flags, format, ap));
	(void)ap;
}
