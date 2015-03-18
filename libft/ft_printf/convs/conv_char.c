/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 20:12:19 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/15 12:06:59 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						conv_e(va_list ap, t_pfflags *flags, char *buff)
{
	static char			c[2] = "?";

	c[0] = flags->char_err;
	if (!c[0])
	{
		--*(flags->index);
		return (-1);
	}
	return (format_str(c, flags, buff));
	(void)ap;
}

int						conv_lchar(va_list ap, t_pfflags *flags, char *buff)
{
	static wchar_t		wc[2] = L"?";

	wc[0] = va_arg(ap, wchar_t);
	if (!wc[0])
	{
		BIT_ON(flags->flg, 63);
		return (format_str("\0", flags, buff));
	}
	return (format_wstr(wc, flags, buff));
}

int						conv_uchar(va_list ap, t_pfflags *flags, char *buff)
{
	static char			c[2] = "?";

	if (BIT_VAL(flags->flg, 6))
		return (conv_lchar(ap, flags, buff));
	c[0] = (unsigned char)va_arg(ap, int);
	BIT_ON(flags->flg, 63);
	return (format_str(c, flags, buff));
}

int						conv_char(va_list ap, t_pfflags *flags, char *buff)
{
	static char			c[2] = "?";

	if (BIT_VAL(flags->flg, 6))
		return (conv_lchar(ap, flags, buff));
	c[0] = (signed char)va_arg(ap, int);
	BIT_ON(flags->flg, 63);
	return (format_str(c, flags, buff));
}
