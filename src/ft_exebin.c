/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exebin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 18:33:11 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/18 15:19:38 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

#include <stdio.h>
static char	*ft_exe_bin_path(char *name)
{
	char			**p;
	char			*path;
	DIR				*dir;
	struct dirent	*dd;

	if (!(path = get_env("PATH")))
		return (NULL);
	p = ft_strsplit(path, ':');
	while (*p)
	{
		if ((dir = opendir(*p)))
		{
			while ((dd = readdir(dir)))
			{
				if (!ft_strcmp(dd->d_name, name))
					return (ft_strjoin(*p, ft_strjoin("/", dd->d_name)));
			}
			closedir(dir);
		}
		p++;
	}
	return (NULL);
}

static int	ft_exebin_fork(char *path, char **av, char **env)
{
	pid_t	pid;
	int		ret;

	if ((pid = fork()) > 0)
	{
		wait(&ret);
		if ((ret & 0xFF00) >> 8 != 0)
			ft_printf("error code: %d\n", (ret & 0xFF00) >> 8);
	}
	if (pid == 0)
		exit(execve(path, av, env));
	return ((ret & 0xFF00) >> 8);
}

int			ft_exebin(char *path, char **av, char **env)
{
	char	*tmp;

	tmp = NULL;
	if (access(path, F_OK) != -1 || ((tmp = ft_exe_bin_path(path)) != NULL))
	{
		if (tmp != NULL)
			path = tmp;
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
