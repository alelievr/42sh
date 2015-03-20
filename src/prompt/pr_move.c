/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:38:48 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/20 10:16:10 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static inline void		pr_move_shift_left(t_prompt *d)
{
	d->index--;
	while (d->index && (d->buff[d->index] == ' '))
		d->index--;
	while (d->index && (d->buff[d->index] != ' '))
		d->index--;
	if (d->buff[d->index] == ' ')
		d->index++;
}

static inline void		pr_move_shift_right(t_prompt *d)
{
	d->index++;
	while (d->buff[d->index] && (d->buff[d->index] != ' '))
		d->index++;
	while (d->buff[d->index] && (d->buff[d->index] == ' '))
		d->index++;
}

static inline void		pr_move_shift_up(t_prompt *d)
{
	if (d->index > d->col - 1)
		d->index -= d->col;
	else
		d->index = 0;
}

static inline void		pr_move_shift_down(t_prompt *d)
{
	if (d->index + d->col < ft_strlen(d->buff))
		d->index += d->col;
	else
		d->index = ft_strlen(d->buff);
}

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
	else if ((d->key == PR_S_LE) && d->index)
		pr_move_shift_left(d);
	else if ((d->key == PR_S_RI) && (d->buff[d->index]))
		pr_move_shift_right(d);
	else if (d->key == PR_S_UP)
		pr_move_shift_up(d);
	else if (d->key == PR_S_DO)
		pr_move_shift_down(d);
}
