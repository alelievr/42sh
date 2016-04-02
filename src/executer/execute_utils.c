/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 19:08:48 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/02 19:10:09 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			exe_get_pipe_number(t_command *c)
{
	int		pipes;

	pipes = 0;
	while (c->next)
	{
		c = c->next;
		pipes++;
	}
	return (pipes);
}
