/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 01:52:41 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/31 18:52:19 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int						lex_rredir(char ***word, t_commandline **cmd)
{
	t_redirection	r;

	if (!get_current_operator(*cmd))
		LEXER_ERROR("syntax error near `%s'\n", **word);
	if (!lex_redir_file_template(OP_REDIR_R, &r, STDOUT_FILENO, *word))
		return (0);
	if (!add_redir_to_current_command(r, cmd))
		return (0);
	(*word)++;
	return (1);
}

int						lex_drredir(char ***word, t_commandline **cmd)
{
	t_redirection	r;

	if (!get_current_operator(*cmd))
		LEXER_ERROR("syntax error near `%s'\n", **word);
	if (!lex_redir_file_template(OP_DREDIR_R, &r, STDOUT_FILENO, *word))
		return (0);
	if (!add_redir_to_current_command(r, cmd))
		return (0);
	(*word)++;
	return (1);
}

int						lex_lredir(char ***word, t_commandline **cmd)
{
	(void)word;
	(void)cmd;
	return (0);
}

int						lex_dlredir(char ***word, t_commandline **cmd)
{
	(void)word;
	(void)cmd;
	return (0);
}

int						lex_fdredir(char ***word, t_commandline **cmd)
{
	char			**w;
	t_operator		*o;
	t_redirection	r;

	w = *word;
	if (!w[1])
		LEXER_ERROR("missing out identifier for `%s\n", *w);
	o = get_current_operator(*cmd);
	ft_bzero(&r, sizeof(r));
	r.type = OP_REDIR_R;
	if (!o)
		LEXER_ERROR("syntax error near `%s'\n", *w);
	if (!ft_strcmp(*w, "-"))
		r.fd_to = CLOSE_FD;
	if (cmd_globing_match(*w, "[0-9]*"))
		r.fd_from = atoi(*w);
	if (!*(w + 1) || is_operator(*(w + 1)))
		LEXER_ERROR("bad out identifier: `%s'\n", *(w + 1));
	if (cmd_globing_match("[0-9]*", *(w + 1)))
		r.fd_to = atoi(*(w + 1));
	else
		r.file = ft_strdup(*(w + 1));
	if (!add_redir_to_current_command(r, cmd))
		return (0);
	(*word)++;
	return (1);
}
