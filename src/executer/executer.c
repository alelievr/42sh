/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 01:48:19 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/01 18:32:59 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

/*
 **	Semicolon management:
*/

int					executer(t_commandline *cl)
{
	while (cl)
	{
		execute_commandline(cl);
		while (cl->type != OP_NO_OP && cl->type != OP_SEMICOLON)
			cl = cl->next;
		if (cl->type == OP_NO_OP)
			break ;
		if (cl->type != OP_NO_OP)
			cl = cl->next;
	}
	return (0);
}
