/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_multiline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:38:36 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/24 20:07:38 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

size_t		get_max_row(t_prompt *p)
{
	size_t	ret;
	size_t	i;

	i = -1;
	ret = 1;
	while (p->buff[++i])
		if (p->buff[i] == '\n')
			ret++;
	return (ret);
}

size_t		get_col_index(t_prompt *p)
{
	size_t	start_bound;

	start_bound = p->index;
	while (start_bound && p->buff[start_bound] != '\n')
		--start_bound;
	return (p->index - start_bound);
}

size_t		get_row_index(t_prompt *p)
{
	size_t	ret;
	size_t	i;

	i = -1;
	ret = 1;
	while (p->buff[++i] && i != p->index)
		if (p->buff[i] == '\n')
			ret++;
	return (ret);
}

void		get_row_bounds(t_prompt *p, size_t *start, size_t *end)
{
	(void)p;
	(void)start;
	(void)end;
}

size_t		get_prompt_length(t_prompt *p)
{
	(void)p;
	return (2);
}
