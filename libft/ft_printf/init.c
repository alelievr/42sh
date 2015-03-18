/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 18:40:55 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 20:01:52 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						(*g_convs[128]) (va_list ap, t_pfflags *fl, char *buf) =
{
	conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e,
	conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e,
	conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e,
	conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e,
	conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e,
	conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e,
	conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e,
	conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e,

	conv_e, conv_e, conv_e, conv_lchar, conv_lint, conv_e, conv_e, conv_e,
	conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_luoct,
	conv_e, conv_e, conv_e, conv_lstr, conv_e, conv_ludec, conv_e, conv_e,
	conv_uhexmaj, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e, conv_e,
	conv_e, conv_e, conv_e, conv_uchar, conv_int, conv_e, conv_e, conv_e,
	conv_e, conv_int, conv_e, conv_e, conv_e, conv_e, conv_e, conv_uoct,
	conv_ptr, conv_e, conv_e, conv_str, conv_e, conv_udec, conv_e, conv_e,
	conv_uhex, conv_e, conv_e, conv_e, conv_e, conv_color, conv_e, conv_e,
};

int						(*g_flags[128]) (t_pfflags *flags, const char *format,
							va_list ap) =
{
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	flag_space, NULL, NULL, flag_prefix, NULL, NULL, NULL, NULL,
	NULL, NULL, flag_star, flag_plus, NULL, flag_minus, flag_prec, NULL,
	flag_zero, flag_number, flag_number, flag_number,
	flag_number, flag_number, flag_number, flag_number,
	flag_number, flag_number, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, flag_basemaj, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, flag_base, NULL, NULL, NULL, NULL, NULL,
	flag_short, NULL, flag_j, NULL, flag_long, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, flag_z, flag_color, NULL, NULL, NULL, NULL,
};
