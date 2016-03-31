/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 01:29:12 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/01 01:19:24 by alelievr         ###   ########.fr       */
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
	c->type = OP_OR;
	c->next = lex_new_commandline();
	return (1);
}

int			lex_and(char ***word, t_commandline **cmd)
{
	t_commandline	*c;
	char			**w;

	w = *word;
	c = get_current_commandline(*cmd);
	if (!c || !c->command || !c->command->list)
		LEXER_ERROR("nothing to execute before &&\n");
	if (!*(w + 1))
		LEXER_ERROR("nothing after &&\n");
	c->type = OP_AND;
	c->next = lex_new_commandline();
	return (1);
}

int			lex_semicolon(char ***word, t_commandline **cmd)
{
	t_commandline	*c;
	char			**w;

	w = *word;
	c = get_current_commandline(*cmd);
	if (!c || !c->command || !c->command->list)
	{
		if (*cmd)
			(*cmd) = (*cmd)->next;
		else
			LEXER_ERROR("nothing to execute\n");
		c = get_current_commandline(*cmd);
	}
	if (!*(w + 1))
		LEXER_ERROR("nothing after ;\n");
	c->type = OP_SEMICOLON;
	c->next = lex_new_commandline();
	return (1);
}

int			lex_background(char ***word, t_commandline **cmd)
{
	t_commandline	*c;
	char			**w;
	t_command		*com;

	w = *word;
	c = get_current_commandline(*cmd);
	if (!c || !c->command || !c->command->list || !c->command->list->bin)
		LEXER_ERROR("nothing to do in background\n");
	if (!ft_strcmp(w[1], "||") || !ft_strcmp(w[1], "&&")
			|| !ft_strcmp(w[1], "|") || !ft_strcmp(w[1], "&"))
		LEXER_ERROR("syntax error near `&'\n");
	com = get_current_command(*cmd);
	com->background = 1;
	return (1);
}
