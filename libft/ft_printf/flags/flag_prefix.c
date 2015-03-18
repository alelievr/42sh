/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 16:49:20 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:09:15 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_prefix(t_pfflags *flags, const char *format,
							va_list ap)
{
	BIT_ON(flags->flg, 5);
	return (1);
	(void)ap;
	(void)format;
}
