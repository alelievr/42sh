/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:47:06 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/19 11:58:32 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void					pr_del(t_prompt *d)
{
	size_t				tmp;

	if (((d->key == PR_DEL) && (d->buff[d->index]))
			|| ((d->key == PR_BACK) && (d->index)))
	{
		if (d->key == PR_BACK)
			d->index--;
		tmp = d->index;
		while (d->buff[tmp])
		{
			d->buff[tmp] = d->buff[tmp + 1];
			++tmp;
		}
	}
	else if (d->key == PR_C_U)
	{
		d->buff[0] = '\0';
		d->index = 0;
	}
}
