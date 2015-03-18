/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:58:40 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:09:06 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_plus(t_pfflags *flags, const char *format,
							va_list ap)
{
	BIT_ON(flags->flg, 3);
	return (1);
	(void)ap;
	(void)format;
}
