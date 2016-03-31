/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_current.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 02:01:21 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/31 16:56:02 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_commandline	*get_current_commandline(t_commandline *cl)
{
	while (cl->next)
		cl = cl->next;
	return (cl);
}

t_command		*get_current_command(t_commandline *cl)
{
	t_command	*ret;

	if (!cl->command)
		return (NULL);
	ret = cl->command;
	while (ret->next)
		ret = ret->next;
	return (ret);
}

t_operator		*get_current_operator(t_commandline *cl)
{
	t_command	*c;

	if (!cl->command || !cl->command->list)
		return (NULL);
	c = cl->command;
	while (c->next)
		c = c->next;
	return (c->list);
}
