/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 22:42:39 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/25 18:03:54 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		pr_history_up(t_prompt *d)
{
	t_list	*next_history;

	next_history = get_history_index(d->history_index);
	if (next_history)
	{
		++(d->history_index);
		ft_strlcpy(d->buff, next_history->content, sizeof(d->buff));
		d->index = ft_strlen(d->buff) - 1;
	}
	else
		BELL;
	(void)d;
}

void		pr_history_dw(t_prompt *d)
{
	t_list	*prev_history;

	if (d->history_index < 2)
		return ;
	prev_history = get_history_index(d->history_index - 2);
	if (prev_history)
	{
		--(d->history_index);
		ft_strlcpy(d->buff, prev_history->content, sizeof(d->buff));
		d->index = ft_strlen(d->buff) - 1;
	}
}

void		pr_history(t_prompt *d)
{
	static char		currentcmd[0xF0000];
	size_t			len;

	if (d->history_index == 0 && d->key == PR_UP)
		ft_strlcpy(currentcmd, d->buff, sizeof(currentcmd));
	else if (d->history_index == 0)
		BELL;
	if (d->history_index == 1 && d->key == PR_DW)
	{
		--(d->history_index);
		ft_strlcpy(d->buff, currentcmd, sizeof(currentcmd));
		len = ft_strlen(currentcmd);
		d->index = (len) ? len - 1 : 0;
		return ;
	}
	if (d->key == PR_UP)
		pr_history_up(d);
	else
		pr_history_dw(d);
}
