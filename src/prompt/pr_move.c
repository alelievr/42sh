/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:38:48 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/25 15:40:59 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static inline size_t	pr_get_cursor_col_buff(t_prompt *p)
{
    size_t	start_bound;

    start_bound = p->index;
    while (start_bound && p->buff[start_bound] != '\n')
	        --start_bound;
    return (p->index - start_bound);
}

static inline void		pr_move_shift_left(t_prompt *d)
{
	d->index--;
	while (d->index && (d->buff[d->index] == ' ' && d->buff[d->index] != '\n'))
		d->index--;
	while (d->index && (d->buff[d->index] != ' ' || d->buff[d->index] == '\n'))
		d->index--;
	if (d->buff[d->index] == ' ')
		d->index++;
}

static inline void		pr_move_shift_right(t_prompt *d)
{
	d->index++;
	while (d->buff[d->index] &&
			(d->buff[d->index] != ' ' && d->buff[d->index] != '\n'))
		d->index++;
	while (d->buff[d->index]
			&& (d->buff[d->index] == ' ' || d->buff[d->index] == '\n'))
		d->index++;
}

static inline void		pr_move_shift_up(t_prompt *d)
{
	size_t		r_index;
	size_t		first_line;
	size_t		i;

	first_line = 1;
	i = d->index + 1;
	while (--i)
		if (d->buff[i] == '\n')
			first_line = 0;
	if (first_line)
		d->index = 0;
	else
	{
		r_index = pr_get_cursor_col_buff(d);
		d->index -= r_index + 1;
	}
}

static inline void		pr_move_shift_down(t_prompt *d)
{
	size_t		last_line;
	size_t		i;

	last_line = 1;
	i = d->index - 1;
	while (d->buff[++i])
		if (d->buff[i] == '\n')
		{
			last_line = 0;
			break ;
		}
	if (last_line)
		d->index = ft_strlen(d->buff) - 1;
	else
	{
		while (d->buff[d->index] != '\n' && d->buff[d->index])
			d->index++;
		d->index++;
	}
}

void					pr_move(t_prompt *d)
{
	if ((d->key == PR_RI) && (d->buff[d->index]) && d->buff[d->index + 1] != '\n')
		d->index++;
	else if ((d->key == PR_LE) && d->index && d->buff[d->index - 1] != '\n')
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
