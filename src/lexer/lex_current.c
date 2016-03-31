/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_current.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 02:01:21 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/31 03:43:45 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

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
	t_operator	*op;

	if (!(op = get_current_operator(*cmd)))
	{
		if (!(*cmd)->command)
			(*cmd)->command = lex_new_command();
		if (!(*cmd)->command->list)
			(*cmd)->command->list = lex_new_operator();
		op = get_current_operator(*cmd);
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
