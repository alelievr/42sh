/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:02:12 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/02 20:02:17 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						conv_color(va_list ap, t_pfflags *flags, char *buff)
{
	static char			c[2] = "}";

	if (!BIT_VAL(flags->flg, 62))
	{
		BIT_ON(flags->flg, 63);
		return (format_str(c, flags, buff));
	}
	BIT_OFF(flags->flg, 62);
	return (format_str(flags->color, flags, buff));
	(void)ap;
}
