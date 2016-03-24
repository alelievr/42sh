/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_unterminated_seq.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 01:52:39 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/24 19:52:19 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			check_unterminated_sequences(t_prompt *d)
{
	size_t		len;
	size_t		i;
	int			b;

	b = 0;
	len = ft_strlen(d->buff);
	if (d->key == 4 && *(d->buff))
		return (1);
	i = (size_t)-1;
	while (d->buff[++i])
	{
		if (d->buff[i] == '\'' && (i == 0 || (d->buff[i - 1] != '\\')))
			b = ((b >> 0) & 1) ? b ^ (1 << 0) : b | (1 << 0);
		if (d->buff[i] == '`' && (i == 0 || (d->buff[i - 1] != '\\')))
			b = ((b >> 1) & 1) ? b ^ (1 << 1) : b | (1 << 1);
		if (d->buff[i] == '\"' && (i == 0 || (d->buff[i - 1] != '\\')))
			b = ((b >> 2) & 1) ? b ^ (1 << 2) : b | (1 << 2);
	}
	if ((len && d->buff[len - 1] == '\\') || b)
	{
		pr_addchar(d, '\n');
		pr_initline(d, PR_NEW_LINE);
		return (1);
	}
	return (!!b);
}
