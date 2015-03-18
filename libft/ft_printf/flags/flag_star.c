/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:52:47 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:09:22 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_star(t_pfflags *flags, const char *format,
							va_list ap)
{
	int					n;

	n = va_arg(ap, int);
	flags->nformat = ABS(n);
	if (n < 0)
		BIT_ON(flags->flg, 8);
	return (1);
	(void)format;
}
