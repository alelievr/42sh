/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 13:26:10 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 16:41:31 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int		nbits(unsigned int nbr)
{
	register int		i;

	i = 1;
	while (nbr >>= 1)
		i++;
	return (i);
}

static inline int		strwlen(const wchar_t *wstr, t_pfflags *flags)
{
	register int		n;
	int					tmp;
	register int		i;
	int					bits;

	n = 0;
	i = -1;
	while (wstr[++i])
	{
		tmp = n;
		bits = nbits((unsigned int)wstr[i]);
		if (bits < 8)
			n += 1;
		else if (bits < 12)
			n += 2;
		else if (bits < 17)
			n += 3;
		else
			n += 4;
		if (BIT_VAL(flags->flg, 13) && (n > flags->prec))
			return (tmp);
	}
	return (n);
}

static inline int		cpywchar(const wchar_t wchar, char *str)
{
	int					n;
	int					i;

	i = -1;
	n = nbits((unsigned int)wchar);
	if (n > 7)
	{
		if (n > 11)
		{
			if (n > 16)
			{
				str[++i] = (char)((((unsigned int)wchar >> 18) & 7) | 240);
				str[++i] = (char)((((unsigned int)wchar >> 12) & 63) | 128);
			}
			else
				str[++i] = (char)((((unsigned int)wchar >> 12) & 15) | 224);
			str[++i] = (char)((((unsigned int)wchar >> 6) & 63) | 128);
		}
		else
			str[++i] = (char)((((unsigned int)wchar >> 6) & 31) | 192);
		str[++i] = (char)(((unsigned int)wchar & 63) | 128);
	}
	else
		str[++i] = (char)(wchar);
	return (i + 1);
}

static inline int		write_wstr(const wchar_t *wstr, t_pfflags *flags,
							char *buff)
{
	int					i;
	int					itmp;
	int					index;

	i = -1;
	index = -1;
	while (wstr[++i])
	{
		itmp = index;
		index += cpywchar(wstr[i], buff + index + 1);
		if (BIT_VAL(flags->flg, 13) && (index > flags->prec - 1))
			return (itmp);
	}
	return (index);
}

int						format_wstr(const wchar_t *wstr, t_pfflags *flags,
							char *buff)
{
	int					n;
	int					i;
	int					index;
	int					format;

	n = strwlen(wstr, flags);
	format = flags->nformat * (BIT_VAL(flags->flg, 8) ? -1 : 1);
	i = n - 1;
	index = -1;
	if (format > 0)
		while (++i < format)
			buff[++index] = (BIT_VAL(flags->flg, 2) ? '0' : ' ');
	index += write_wstr(wstr, flags, buff + index + 1) + 1;
	i = n - 1;
	if (format < 0)
		while (++i < -format)
			buff[++index] = ' ';
	return (index);
}
