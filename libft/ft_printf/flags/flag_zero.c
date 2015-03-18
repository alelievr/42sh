/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:56:44 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:09:31 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_zero(t_pfflags *flags, const char *format,
							va_list ap)
{
	BIT_ON(flags->flg, 2);
	return (1);
	(void)ap;
	(void)format;
}
