/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 01:29:12 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/31 17:19:49 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			lex_pipe(char ***word, t_commandline **cmd)
{
	t_command		*last;
	t_commandline	*c;
	char			**w;

	w = *word;
	c = get_current_commandline(*cmd);
	if (!c || !c->command || !c->command->list)
		LEXER_ERROR("nothing to execute before pipe\n");
	if (!*(w + 1))
		LEXER_ERROR("nothing after pipe\n");
	last = get_current_command(*cmd);
	last->next = lex_new_command();
	last->next->list = lex_new_operator();
	return (1);
}

int			lex_or(char ***word, t_commandline **cmd)
{
	t_commandline	*c;
	char			**w;

	w = *word;
	c = get_current_commandline(*cmd);
	if (!c || !c->command || !c->command->list)
		LEXER_ERROR("nothing to execute before ||\n");
	if (!*(w + 1))
		LEXER_ERROR("nothing after ||\n");
	(*cmd)->next = lex_new_commandline();
	return (0);
}

int			lex_and(char ***word, t_commandline **cmd)
{
	(void)word;
	(void)cmd;
	return (0);
}

int			lex_semicolon(char ***word, t_commandline **cmd)
{
	(void)word;
	(void)cmd;
	return (0);
}

int			lex_background(char ***word, t_commandline **cmd)
{
	(void)word;
	(void)cmd;
	return (0);
}
