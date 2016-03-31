/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 01:35:55 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/31 03:00:04 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_commandline			*lex_new_commandline(void)
{
	t_commandline	*new;

	if (!(new = malloc(sizeof(t_commandline))))
		m_error();
	new->command = NULL;
	new->next = NULL;
	new->type = OP_NO_OP;
	return (new);
}

t_command				*lex_new_command(void)
{
	t_command	*new;

	if (!(new = malloc(sizeof(t_command))))
		m_error();
	ft_bzero(new, sizeof(t_command));
	return (new);
}

t_operator				*lex_new_operator(void)
{
	t_operator	*new;

	if (!(new = malloc(sizeof(t_operator))))
		m_error();
	ft_bzero(new, sizeof(t_operator));
	new->redirs[0].type = OP_NO_OP;
	return (new);
}
