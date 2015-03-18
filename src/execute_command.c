/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 17:09:04 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/18 17:43:46 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		(*op)[11] = {
							ft_pipe,
							ft_redir_stdin_stdout,
							ft_right_redir,
							};

int			execute_command(t_operate *b)
{
	while (b)
	{
		op[b->type](b->len, b->value);
		b = b->next;
	}
}
