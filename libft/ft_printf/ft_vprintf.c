/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 12:46:51 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:17:45 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define SAFE_CHAR(c)	(unsigned int)(127 & (c))

static inline void		reset_flags(t_pfflags *flags)
{
	flags->flg = 0;
	flags->base = 10;
	flags->nformat = 0;
	flags->prec = 0;
}

int						ft_vsprintf(char *buff, const char *format, va_list ap)
{
	static t_pfflags	flags = {0, 10, 0, 0, "\033[", '?', NULL, 0};
	int					index;
	int					i_buff;

	index = -1;
	i_buff = 0;
	flags.index = &index;
	while (format[++index])
	{
		if (format[index] == '%')
		{
			reset_flags(&flags);
			while (g_flags[SAFE_CHAR(format[++index])] != NULL)
				index += g_flags[SAFE_CHAR(format[index])]
					(&flags, format + index, ap) - 1;
			i_buff += g_convs[SAFE_CHAR(flags.char_err = format[index])]
				(ap, &flags, buff + i_buff) + 1;
		}
		else
			buff[i_buff++] = format[index];
	}
	buff[i_buff] = '\0';
	return (i_buff);
}

int						ft_vfprintf(int fd, const char *format, va_list ap)
{
	char				buff[FTPF_BUFFSIZE];
	int					ret;

	ret = ft_vsprintf(buff, format, ap);
	write(fd, buff, ret);
	return (ret);
}

int						ft_vprintf(const char *format, va_list ap)
{
	return (ft_vfprintf(1, format, ap));
}
