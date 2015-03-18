/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 21:27:38 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:09:18 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_short(t_pfflags *flags, const char *format,
							va_list ap)
{
	if (BIT_VAL(flags->flg, 9) && BIT_VAL(flags->flg, 10))
		return (1);
	if (BIT_VAL(flags->flg, 9))
		BIT_ON(flags->flg, 10);
	else
		BIT_ON(flags->flg, 9);
	return (1);
	(void)ap;
	(void)format;
}
