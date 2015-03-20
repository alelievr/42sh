/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_addch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 10:02:38 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/20 10:06:16 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void					pr_addchar(t_prompt *d)
{
	size_t				tmp;

	tmp = ft_strlen(d->buff);
	d->buff[tmp + 1] = '\0';
	while (tmp != d->index)
	{
		d->buff[tmp] = d->buff[tmp - 1];
		--tmp;
	}
	d->buff[tmp] = d->key;
	++(d->index);
}
