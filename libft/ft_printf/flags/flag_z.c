/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 21:31:24 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:09:25 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_z(t_pfflags *flags, const char *format,
							va_list ap)
{
	BIT_ON(flags->flg, 12);
	return (1);
	(void)ap;
	(void)format;
}
