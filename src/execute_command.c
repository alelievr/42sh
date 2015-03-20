/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 17:09:04 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/20 12:21:45 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <fcntl.h>

void		(*op[13])(int, char **) = {
							ft_pipe,
							ft_redir_stdin_stdout,
							ft_right_redir,
							ft_exec,
							ft_error_right_redir,
							ft_left_redir,
							ft_double_left_redir,
							ft_double_right_redir,
							ft_error_double_right_redir,
							NULL,
							NULL,
							NULL,
							NULL
							};

int			execute_command(t_operate *b)
{
	while (b)
	{
		ft_fprintf(open("/dev/tty", O_RDWR), "%i\n", b->type);
		op[b->type](b->len, b->value);
		b = b->next;
	}
	return (0);
}
