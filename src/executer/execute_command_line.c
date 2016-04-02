/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:15:33 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/01 23:09:51 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#define LAST_CMD(x)		(x == OP_NO_OP || x == OP_SEMICOLON)

/*
 **	|| and && management
*/

int				execute_commandline(t_commandline *cl)
{
	int		res;
	int		last_type;

	while (42)
	{
		res = execute_command(cl->command);
		if (cl->type == OP_NO_OP || cl->type == OP_SEMICOLON)
			break ;
		if (res == COMMAND_OK && cl->type == OP_AND)
		{
			last_type = cl->type;
			cl = cl->next;
			continue ;
		}
		if (res == COMMAND_OK && cl->type == OP_OR)
			while (cl->type == OP_OR && ((last_type = cl->type) | 1))
				cl = cl->next;
		if (res == COMMAND_OK && LAST_CMD(cl->type) && last_type == OP_OR)
			break ;
		if (cl->type != OP_NO_OP)
			cl = cl->next;
	}
	return (!!res);
}
