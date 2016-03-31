/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 01:52:41 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/01 01:01:35 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int						lex_fd_rredir(char ***word, t_commandline **cmd)
{
	t_redirection	r;
	int				fd_in;

	if (!ft_strcmp(**word, ">"))
		fd_in = STDOUT_FILENO;
	else
		fd_in = ft_atoi(**word);
	if (!get_current_operator(*cmd))
		LEXER_ERROR("syntax error near `%s'\n", **word);
	if (!lex_redir_file_template(OP_REDIR_R, &r, fd_in, *word))
		return (0);
	if (!ft_strcmp((*word)[1], "-"))
	{
		r.fd_to = CLOSE_FD;
		free(r.file);
		r.file = NULL;
	}
	if (!add_redir_to_current_command(r, cmd))
		return (0);
	(*word)++;
	return (1);
}

int						lex_lredir(char ***word, t_commandline **cmd)
{
	t_redirection	r;
	char			**w;

	w = *word;
	if (!lex_check_next_value(cmd, *word))
		return (0);
	ft_bzero(&r, sizeof(t_redirection));
	r.type = OP_REDIR_L;
	if (!is_file(w[1], O_RDONLY))
		LEXER_ERROR("bad input file: `%s'\n", w[1]);
	r.file = ft_strdup(w[1]);
	add_redir_to_current_command(r, cmd);
	(*word)++;
	return (1);
}

int						lex_all_rredir(char ***word, t_commandline **cmd)
{
	char			**w;
	t_redirection	r;

	w = *word;
	if (!lex_check_next_value(cmd, w))
		return (0);
	ft_bzero(&r, sizeof(r));
	if (!ft_strcmp(*w, ">&"))
		r.fd_from = STDOUT_AND_STDERR;
	r.type = OP_REDIR_R;
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
