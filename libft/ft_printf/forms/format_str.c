/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 15:32:17 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/01/17 19:20:59 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 2	-	padding with '0'
** 128	-	left formating
** ?	-	TODO: cut if ABS(format) < strlen
*/

static inline void		aff_str(const char *str, t_pfflags *flags,
							char *buff, int *index)
{
	int					i;

	i = -1;
	if (BIT_VAL(flags->flg, 63))
		buff[++*index] = str[0];
	else
	{
		while (str[++i] && (!BIT_VAL(flags->flg, 13) || (i < flags->prec)))
			buff[++*index] = str[i];
	}
}

int						format_str(const char *str, t_pfflags *flags,
							char *buff)
{
	size_t				n;
	int					i;
	int					index;
	int					format;

	if (BIT_VAL(flags->flg, 13))
		n = (BIT_VAL(flags->flg, 63) ? 1 :
				MIN((size_t)flags->prec, ft_strlen(str)));
	else
		n = (BIT_VAL(flags->flg, 63) ? 1 : ft_strlen(str));
	format = flags->nformat * (BIT_VAL(flags->flg, 8) ? -1 : 1);
	i = (int)n - 1;
	index = -1;
	if (format > 0)
		while (++i < format)
			buff[++index] = (BIT_VAL(flags->flg, 2) ? '0' : ' ');
	aff_str(str, flags, buff, &index);
	if (format < 0)
		while (++i < -format)
			buff[++index] = ' ';
	return (index);
}
