/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exebin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 18:33:11 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/16 21:19:13 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_exebin_fork(char *path, char **av, char **env)
{
	pid_t	pid;
	int		ret;

	if ((pid = fork()) > 0)
	{
		wait(&ret);
		if ((ret & 0xFF00) >> 8 != 0)
		{
			ft_putstr("error code: ");
			ft_putnbr((ret & 0xFF00) >> 8);
			ft_putchar('\n');
		}
	}
	if (pid == 0)
		exit(execve(path, av, env));
	return ((ret & 0xFF00) >> 8);
}

int			ft_exebin(char *path, char **av, char **env)
{
	if (access(path, F_OK) != -1)
	{
		if (access(path, X_OK) != -1)
			return (ft_exebin_fork(path, av, env));
		else
		{
			ft_putstr(path);
			ft_putstr(": permission denied !\n");
		}
	}
	else
	{
		ft_putstr(path);
		ft_putstr(": no such file or directory\n");
	}
	return (-1);
}
