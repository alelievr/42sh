/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_addch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 10:02:38 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/25 17:58:55 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			pr_addchar(t_prompt *d, char c) __attribute__((overloadable))
{
	size_t				tmp;
	size_t		len;

	len = ft_strlen(d->buff);
	if (sizeof(d->buff) < len + 1)
		return ;
	tmp = len;
	d->buff[tmp + 1] = '\0';
	while (tmp != d->index && tmp)
	{
		d->buff[tmp] = d->buff[tmp - 1];
		--tmp;
	}
	d->buff[tmp] = c;
	++(d->index);
}

void			pr_addchar(t_prompt *d) __attribute__((overloadable))
{
	pr_addchar(d, (char)d->key);
}

void			pr_addstr(t_prompt *d, char *s, size_t len)
{
	size_t		tmp;
	size_t		rlen;

	rlen = ft_strlen(d->buff);
	if (sizeof(d->buff) < rlen + len)
		return ;
	tmp = rlen;
	while (*s)
	{
		if (*s == ' ')
		{
			d->buff[tmp++] = '\\';
			++(d->index);
		}
		d->buff[tmp++] = *s++;
		++(d->index);
	}
	d->buff[tmp] = 0;
}
