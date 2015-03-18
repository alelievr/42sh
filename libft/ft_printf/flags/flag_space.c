/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:59:09 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:09:20 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						flag_space(t_pfflags *flags, const char *format,
							va_list ap)
{
	BIT_ON(flags->flg, 4);
	return (1);
	(void)ap;
	(void)format;
}
