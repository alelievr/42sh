/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:02:14 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/02 19:58:14 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flag:
** %{c}
**   0	erase all style
**   !	cancel one style
**   b	bold
**   u	underline
**   r	reverse
** ---
**   F	foreground
**   B	background
*/

static inline void		cancel(t_pfflags *flags, const char *format,
							int *i, int *j)
{
	flags->color[++*j] = '2';
	if (format[++*i] == 'b')
		flags->color[++*j] = '2';
	else if (format[*i] == 'u')
		flags->color[++*j] = '4';
	else if (format[*i] == 'r')
		flags->color[++*j] = '7';
	else if (format[*i] == 'F')
	{
		flags->color[*j] = '3';
		flags->color[++*j] = '9';
	}
	else if (format[*i] == 'B')
	{
		flags->color[*j] = '4';
		flags->color[++*j] = '9';
	}
}

static inline int		style(t_pfflags *flags, const char *format,
							int *i, int *j)
{
	if (format[*i] == '0')
		flags->color[++*j] = '0';
	else if (format[*i] == 'b')
		flags->color[++*j] = '1';
	else if (format[*i] == 'u')
		flags->color[++*j] = '4';
	else if (format[*i] == 'r')
		flags->color[++*j] = '7';
	else
		return (0);
	return (1);
}

static inline void		write_color(t_pfflags *flags, int *j, int color,
							char code)
{
	flags->color[++*j] = code;
	flags->color[++*j] = '8';
	flags->color[++*j] = ';';
	flags->color[++*j] = '5';
	flags->color[++*j] = ';';
	if (color > 99)
		flags->color[++*j] = '0' + color / 100;
	if (color > 9)
		flags->color[++*j] = '0' + (color / 10) % 10;
	flags->color[++*j] = '0' + color % 10;
}

int						flag_color(t_pfflags *flags, const char *format,
							va_list ap)
{
	int					i;
	int					j;

	i = 1;
	j = 1;
	while (format[i] && (j < 200))
	{
		if (style(flags, format, &i, &j))
			;
		else if (format[i] == '!')
			cancel(flags, format, &i, &j);
		else if (format[i] == 'F')
			write_color(flags, &j, va_arg(ap, int) % 256, '3');
		else if (format[i] == 'B')
			write_color(flags, &j, va_arg(ap, int) % 256, '4');
		else
			break ;
		flags->color[++j] = ';';
		++i;
	}
	flags->color[++j] = 'm';
	flags->color[++j] = '\0';
	BIT_ON(flags->flg, 62);
	return (i);
}
