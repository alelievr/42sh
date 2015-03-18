/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:53:31 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:08:54 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_long(t_pfflags *flags, const char *format,
							va_list ap)
{
	if (BIT_VAL(flags->flg, 6) && BIT_VAL(flags->flg, 7))
		return (1);
	if (BIT_VAL(flags->flg, 6))
		BIT_ON(flags->flg, 7);
	else
		BIT_ON(flags->flg, 6);
	return (1);
	(void)ap;
	(void)format;
}
