/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_j.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 21:30:17 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:08:50 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_j(t_pfflags *flags, const char *format,
							va_list ap)
{
	BIT_ON(flags->flg, 11);
	return (1);
	(void)ap;
	(void)format;
}
