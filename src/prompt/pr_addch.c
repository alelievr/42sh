/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_addch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 10:02:38 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/16 01:29:49 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			pr_addchar(t_prompt *d, char c) __attribute__((overloadable))
{
	size_t				tmp;

	if (sizeof(d->buff) < d->len + 1)
		return ;
	tmp = d->len;
	d->buff[tmp + 1] = '\0';
	while (tmp != d->index && tmp)
	{
		d->buff[tmp] = d->buff[tmp - 1];
		--tmp;
	}
	d->buff[tmp] = c;
	++(d->index);
	++(d->len);
}

void			pr_addchar(t_prompt *d) __attribute__((overloadable))
{
	pr_addchar(d, (char)d->key);
}

void			pr_addstr(t_prompt *d, char *s, size_t len)
{
	size_t		tmp;

	if (sizeof(d->buff) < d->len + len)
		return ;
	tmp = d->len;
	while (*s)
	{
		if (*s == ' ')
		{
			d->buff[tmp++] = '\\';
			++(d->index);
			++(d->len);
		}
		d->buff[tmp++] = *s++;
		++(d->index);
	}
	d->buff[tmp] = 0;
	d->len += len;
}
