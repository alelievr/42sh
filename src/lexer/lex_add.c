/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:56:09 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/31 17:59:47 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static int		add_argument_to_binary(t_operator *op, char *w)
{
	if (!op->av_bin)
	{
		if (!(op->av_bin = (char **)malloc(sizeof(char *) * (MAX_BINARY_ARGUMENTS + 1))))
			m_error();
		op->av_bin[0] = NULL;
		op->ac_bin = 0;
	}
	if (op->ac_bin == MAX_BINARY_ARGUMENTS)
		LEXER_ERROR("%s: too many arguments\n", op->bin);
	if (!(op->av_bin[op->ac_bin] = ft_strdup(w)))
		m_error();
	op->av_bin[op->ac_bin + 1] = NULL;
	(op->ac_bin)++;
	return (1);
}

int				add_word_to_current_command(char **word, t_commandline **cmd)
{
	t_operator		*op;
	t_commandline	*c;

	c = get_current_commandline(*cmd);
	if (!(op = get_current_operator(c)))
	{
		if (!c->command)
			c->command = lex_new_command();
		if (!c->command->list)
			c->command->list = lex_new_operator();
		op = get_current_operator(c);
	}
	if (!op->bin)
	{
		if (!(op->bin = ft_strdup(*word)))
			m_error();
		return (add_argument_to_binary(op, op->bin));
	}
	else
		return (add_argument_to_binary(op, *word));
}

int				add_redir_to_current_command(t_redirection r, t_commandline **cmd)
{
	t_commandline	*c;
	t_operator		*op;
	size_t			i;

	c = get_current_commandline(*cmd);
	if (!(op = get_current_operator(c)))
	{
		if (!c->command)
			c->command = lex_new_command();
		if (!c->command->list)
			c->command->list = lex_new_operator();
		op = get_current_operator(c);
	}
	i = -1;
	while (op->redirs[i].type != OP_NO_OP)
		i++;
	if (i == MAX_REDIRECTION_COMMAND - 1)
		LEXER_ERROR("too many redirections for %s\n", op->bin);
	op->redirs[i].type = r.type;
	op->redirs[i].fd_from = r.fd_from;
	op->redirs[i].fd_to = r.fd_to;
	op->redirs[i].file = r.file;
	op->redirs[i + 1].type = OP_NO_OP;
	return (1);
}
