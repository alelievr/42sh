/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:38:57 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:09:02 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_number(t_pfflags *flags, const char *format,
							va_list ap)
{
	flags->nformat = atoi(format);
	return (ft_nbrlen((int64_t)flags->nformat, 10));
	(void)ap;
}
