/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:47:06 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/24 22:28:17 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void					pr_del(t_prompt *d)
{
	size_t				tmp;

	if (((d->key == PR_DEL) && (d->buff[d->index]) && d->buff[d->index + 1] != '\n')
			|| ((d->key == PR_BACK) && (d->index) && d->buff[d->index - 1] != '\n'))
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
	else if (d->key == PR_C_K)
		d->buff[d->index] = '\0';
	else if (d->key == PR_C_U)
	{
		d->buff[0] = '\0';
		d->index = 0;
	}
}
