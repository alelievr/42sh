/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:38:48 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/19 12:11:04 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void					pr_move(t_prompt *d)
{
	if ((d->key == PR_RI) && (d->buff[d->index]))
		d->index++;
	else if ((d->key == PR_LE) && d->index)
		d->index--;
	else if ((d->key == PR_BEG) || (d->key == PR_C_A))
		d->index = 0;
	else if ((d->key == PR_END) || (d->key == PR_C_E))
		d->index = ft_strlen(d->buff);
	else if (d->key == PR_S_LE)
	{
		while (d->index && (d->buff[d->index] == ' '))
			d->index--;
		while (d->index && (d->buff[d->index] != ' '))
			d->index--;
	}
	else if (d->key == PR_S_RI)
	{
		while (d->buff[d->index] && (d->buff[d->index] != ' '))
			d->index++;
		while (d->buff[d->index] && (d->buff[d->index] == ' '))
			d->index++;
	}
}
