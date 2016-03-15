/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_addch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 10:02:38 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/15 16:31:36 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void					pr_addchar(t_prompt *d)
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
	d->buff[tmp] = d->key;
	++(d->index);
	++(d->len);
}

void					pr_addstr(t_prompt *d, char *s, size_t len)
{
	size_t		tmp;

	if (sizeof(d->buff) < d->len + len)
		return ;
	tmp = d->len;
	d->buff[tmp + len] = '\0';
	while (tmp != d->index && (tmp - len + 1))
	{
		d->buff[tmp] = d->buff[tmp - len];
		--tmp;
	}
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
	d->len += len;
}
