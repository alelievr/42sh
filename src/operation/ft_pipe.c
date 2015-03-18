/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:58:55 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/18 16:16:36 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <sys/wait.h>
#include <unistd.h>

int			ft_pipe(int ac, char **av)
{
	pid_t	pid;

	if ((pid = fork) > 0)
	{
	
	}
	if (pid == 0)
	{
		dup2()
	}
}
