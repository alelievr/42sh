/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exebin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 18:33:11 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/11 18:22:25 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

static const char		*g_errors[] = {
	"terminal line hangup",
	"interrupt program",
	"quit program",
	"illegal instruction",
	"trace trap",
	"abort program (formerly SIGIOT)",
	"emulate instruction executed",
	"floating-point exception",
	"kill program",
	"bus error",
	"segmentation violation",
	"non-existent system call invoked",
	"write on a pipe with no reader",
	"real-time timer expired",
	"software termination signal",
	"urgent condition present on socket",
	"stop (cannot be caught or ignored)",
	"stop signal generated from keyboard",
	"continue after stop",
	"child status has changed",
	"background read attempted from control terminal",
	"background write attempted to control terminal",
	"I/O is possible on a descriptor",
	"cpu time limit exceeded",
	"file size limit exceeded",
	"virtual time alarm",
	"profiling timer alarm",
	"Window size change",
	"status request from keyboard",
	"User defined signal 1",
	"User defined signal 2"
};

static int		ft_exebin_fork(char *path, char **av, char **env)
{
	pid_t	pid;
	int		ret;

	if ((pid = fork()) > 0)
	{
		wait(&ret);
		if ((ret & 0xFF) != 0)
			ft_printf("%s: %s\n", path, g_errors[(ret & 0x00FF) % 31 - 1]);
	}
	if (pid == 0)
		exit(execve(path, av, env));
	return ((ret & 0xFF00) >> 8);
}

static int		ft_exebin_concat(char *cur, char *bin, char **av)
{
	static char	path[0xF000];

	ft_strncpy(path, cur, sizeof(path) - ft_strlen(bin) - 3);
	ft_strlcat(path, "/", sizeof(path));
	ft_strlcat(path, bin, sizeof(path));
	if (access(path, F_OK | X_OK) != -1)
	{
		ft_exebin_fork(path, av, g_env);
		return (1);
	}
	return (0);
}

static int		ft_exe_bin_path(char *bin, char **av)
{
	static char	buff[0xF0000];
	char		*tmp_path;
	char		*cur;
	char		*ptr;

	if (!(tmp_path = get_env("PATH")))
		return (0);
	ft_strncpy(buff, tmp_path, sizeof(buff) - 1);
	cur = buff;
	ptr = buff;
	while (*ptr)
	{
		ptr++;
		if (*ptr == ':' || !*ptr)
		{
			*ptr = 0;
			if (ft_exebin_concat(cur, bin, av))
				return (1);
			cur = ptr + 1;
			ptr++;
		}
	}
	return (0);
}

int				ft_exebin(char *path, char **av, char **env)
{
	if (access(path, F_OK | X_OK) != -1 && ft_strchr(path, '/'))
	{
		ft_exebin_fork(path, av, env);
		return (1);
	}
	else
		return (ft_exe_bin_path(path, av));
	(void)env;
}
