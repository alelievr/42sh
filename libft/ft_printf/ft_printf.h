/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 19:36:07 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 12:08:43 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define FTPF_BUFFSIZE	0x400000
# define FTPF_MAXBASE	32

int						ft_printf(const char *format, ...);
int						ft_sprintf(char *buff, const char *format, ...);
int						ft_fprintf(int fd, const char *format, ...);

int						ft_vprintf(const char *format, va_list ap);
int						ft_vsprintf(char *buff, const char *format, va_list ap);
int						ft_vfprintf(int fd, const char *format, va_list ap);

/*
** Flags struct: `flags->flg`
** ---
** flags:
**		1	'X'	upcase for hex
**		2	'0'	zero padding
**		3	'+'	plus flag
**		4	' '	space flag
**		5	'#'	prefix
**		6	'l' first long
**		7	'l' second long
**		8	'-'	minus flag
**		9	'h'	first short
**		10	'h'	second short
**		11	'j'	J
**		12	'z'	Z
**		13	'.'	precision
**		14	'{'	color
** special flags:
**		62	a { has been opened
**		63	null char to be written in 'format_str'
**		64	force prefix displaying (for NULL ptr)
*/

typedef struct			s_pfflags
{
	uint64_t			flg;
	int					base;
	int					nformat;
	int					prec;
	char				color[256];

	int					char_err;
	int					*index;

	int					n_digits;
}						t_pfflags;

/*
** Funcs database
*/

extern int				(*g_convs[128]) (va_list ap, t_pfflags *fl, char *buf);
extern int				(*g_flags[128]) (t_pfflags *flags, const char *format,
							va_list ap);

/*
** format funcs
*/

int						format_str(const char *str, t_pfflags *flags,
							char *buff);
int						format_wstr(const wchar_t *wstr, t_pfflags *flags,
							char *buff);
int						format_int(int64_t nbr, t_pfflags *flags,
							char *buff);
int						format_uint(uint64_t nbr, t_pfflags *flags,
							char *buff);

void					write_uint(uint64_t nbr, char *buff, t_pfflags *flags,
							int *index);
void					write_base(char *buff, int *index, t_pfflags *flags);

/*
** flags.c
**		list of flag functions
*/

int						flag_number(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_prefix(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_long(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_zero(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_plus(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_space(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_minus(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_short(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_j(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_z(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_prec(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_base(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_basemaj(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_star(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_color(t_pfflags *flags, const char *format,
							va_list ap);

/*
** convs.c
**		list of conversion functions
*/

int						conv_e(va_list ap, t_pfflags *flags, char *buf);

int						conv_char(va_list ap, t_pfflags *flags, char *buf);
int						conv_uchar(va_list ap, t_pfflags *flags, char *buf);
int						conv_lchar(va_list ap, t_pfflags *flags, char *buf);
int						conv_int(va_list ap, t_pfflags *flags, char *buf);
int						conv_lint(va_list ap, t_pfflags *flags, char *buf);
int						conv_uoct(va_list ap, t_pfflags *flags, char *buf);
int						conv_luoct(va_list ap, t_pfflags *flags, char *buf);
int						conv_ptr(va_list ap, t_pfflags *flags, char *buf);
int						conv_str(va_list ap, t_pfflags *flags, char *buf);
int						conv_lstr(va_list ap, t_pfflags *flags, char *buf);
int						conv_udec(va_list ap, t_pfflags *flags, char *buf);
int						conv_ludec(va_list ap, t_pfflags *flags, char *buf);
int						conv_uhex(va_list ap, t_pfflags *flags, char *buf);
int						conv_luhex(va_list ap, t_pfflags *flags, char *buf);
int						conv_uhexmaj(va_list ap, t_pfflags *flags, char *buf);
int						conv_color(va_list ap, t_pfflags *flags, char *buf);

#endif
