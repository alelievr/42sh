/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_double_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 21:08:43 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/01 00:57:41 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int				lex_all_drredir(char ***word, t_commandline **cmd)
{
	char			**w;
	t_redirection	r;

	w = *word;
	if (!lex_check_next_value(cmd, w))
		return (0);
	ft_bzero(&r, sizeof(r));
	if (!ft_strcmp(*w, ">>&"))
		r.fd_from = STDOUT_AND_STDERR;
	r.type = OP_DREDIR_R;
	if (!ft_strcmp(*w, "-"))
		r.fd_to = CLOSE_FD;
	if (cmd_globing_match(*w, "[0-9]*"))
		r.fd_from = (ft_atoi(*w) == 1) ? STDOUT_AND_STDERR : (ft_atoi(*w));
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

int				lex_fd_drredir(char ***word, t_commandline **cmd)
{
	t_redirection	r;
	int             fd_in;

	if (!ft_strcmp(**word, ">>"))
		fd_in = STDOUT_FILENO;
	else
		fd_in = ft_atoi(**word);
	if (!get_current_operator(*cmd))
		LEXER_ERROR("syntax error near `%s'\n", **word);
	if (!lex_redir_file_template(OP_DREDIR_R, &r, fd_in, *word))
		return (0);
	if (!add_redir_to_current_command(r, cmd))
		return (0);
	(*word)++;
	return (1);
}

int				lex_dlredir(char ***word, t_commandline **cmd)
{
	t_redirection	r;

	if (!lex_check_next_value(cmd, *word))
		return (0);
	ft_bzero(&r, sizeof(r));
	r.type = OP_DREDIR_L;
	r.fd_from = STDIN_FILENO;
	r.fd_to = PROCESS_FD;
	r.file = NULL;
	if (!add_redir_to_current_command(r, cmd))
		return (0);
	(*word)++;
	return (1);
}

