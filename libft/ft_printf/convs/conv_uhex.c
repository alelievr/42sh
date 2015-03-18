/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:55:18 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/15 11:57:37 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						conv_ptr(va_list ap, t_pfflags *flags, char *buff)
{
	BIT_ON(flags->flg, 5);
	BIT_ON(flags->flg, 64);
	flags->base = 16;
	return (conv_ludec(ap, flags, buff));
}

int						conv_luhex(va_list ap, t_pfflags *flags, char *buff)
{
	flags->base = 16;
	return (conv_ludec(ap, flags, buff));
}

int						conv_uhex(va_list ap, t_pfflags *flags, char *buff)
{
	flags->base = 16;
	return (conv_udec(ap, flags, buff));
}

int						conv_uhexmaj(va_list ap, t_pfflags *flags, char *buff)
{
	flags->base = 16;
	BIT_ON(flags->flg, 1);
	return (conv_udec(ap, flags, buff));
}
