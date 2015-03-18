/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 12:47:08 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:17:25 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf(const char *format, ...)
{
	va_list				vl;
	int					ret;

	va_start(vl, format);
	ret = ft_vprintf(format, vl);
	va_end(vl);
	return (ret);
}

int						ft_sprintf(char *buff, const char *format, ...)
{
	va_list				vl;
	int					ret;

	va_start(vl, format);
	ret = ft_vsprintf(buff, format, vl);
	va_end(vl);
	return (ret);
}

int						ft_fprintf(int fd, const char *format, ...)
{
	va_list				vl;
	int					ret;

	va_start(vl, format);
	ret = ft_vfprintf(fd, format, vl);
	va_end(vl);
	return (ret);
}
