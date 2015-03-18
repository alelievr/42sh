/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uoct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:55:40 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/13 19:39:26 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						conv_luoct(va_list ap, t_pfflags *flags, char *buff)
{
	flags->base = 8;
	return (conv_ludec(ap, flags, buff));
}

int						conv_uoct(va_list ap, t_pfflags *flags, char *buff)
{
	flags->base = 8;
	return (conv_udec(ap, flags, buff));
}
