/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_current.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 02:01:21 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/01 01:15:44 by alelievr         ###   ########.fr       */
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
	t_command		*ret;
	t_commandline	*c;

	c = get_current_commandline(cl);
	if (!c->command)
		return (NULL);
	ret = c->command;
	while (ret->next)
		ret = ret->next;
	return (ret);
}

t_operator		*get_current_operator(t_commandline *cl)
{
	t_command		*c;
	t_commandline	*cline;

	cline = get_current_commandline(cl);
	if (!cline->command || !cline->command->list)
		return (NULL);
	c = cline->command;
	while (c->next)
		c = c->next;
	return (c->list);
}
