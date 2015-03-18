/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 21:00:44 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:08:58 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_minus(t_pfflags *flags, const char *format,
							va_list ap)
{
	BIT_ON(flags->flg, 8);
	return (1);
	(void)ap;
	(void)format;
}
