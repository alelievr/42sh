/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_redir_template.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 18:38:05 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/31 18:51:30 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int				lex_redir_file_template(enum e_operate type, int in_fd,
		t_redirection *r, char **w)
{
	ft_bzero(r, sizeof(t_redirection));
	if (!*(w + 1) || is_operator(*(w + 1)))
		LEXER_ERROR("bad out identifier for `%s'\n", *w);
	r->type = type;
	r->file = ft_strdup(*(w + 1));
	r->fd_from = in_fd;
	return (1);
}
