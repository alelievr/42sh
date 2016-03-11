/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:58:55 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/20 15:15:33 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <sys/wait.h>
#include <unistd.h>
#define PIPE_IN		1
#define PIPE_OUT	0

void		ft_pipe(int ac, char **av)
{
	pid_t	pid;
	int		pdes[2];

	pipe(pdes);
	pid = fork();
	if (pid == -1)
		ft_putstr("Broken pipe !\n");
	if (pid > 0)
	{
		dup2(pdes[PIPE_IN], 1);
		close(pdes[PIPE_OUT]);
		//exec ...
	}
	if (pid == 0)
	{
		wait(NULL);
		close(pdes[PIPE_IN]);
		dup2(pdes[PIPE_OUT], 0);
		//exec2 ...
	}
	(void)ac;
	(void)av;
}
