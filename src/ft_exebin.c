/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exebin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 18:33:11 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/19 16:51:26 by alelievr         ###   ########.fr       */
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

int				wait_process(pid_t pid, char *pname)
{
	int		ret;

	waitpid(pid, &ret, WUNTRACED);
	printf("retcode = %i\n", (ret & 0xFF00) >> 8);
	if ((ret & 0x00FF) % 31 == 3 && WIFSTOPPED(ret))
		ft_printf("\n%i: %s %s\n", pid, "suspended", pname);
	else if ((ret & 0xFF) != 0)
		ft_printf("\n%i: %s\n", pid, g_errors[(ret & 0x00FF) % 31 - 1]);
	return (ret);
}

static int		ft_exebin_fork(char *path, char **av, char **env)
{
	pid_t	pid;
	int		ret;

	if ((pid = fork()) > 0)
	{
		//TODO try to fix this ...
		get_fg_pid(pid, *av, S_RUNNING);
		ret = wait_process(pid, *av);
		get_fg_pid(0, NULL, 0);
	}
	if (pid == 0)
	{
//		setpgid(0, 0);
		exit(execve(path, av, env));
	}
	return ((ret & 0xFF00) >> 8);
}

static int		ft_exe_bin_path(char *bin, char **av)
{
	char		*path;

	path = get_binhash_path(hashstring(bin));
	if (!path)
		return (0);
	ft_exebin_fork(path, av, g_env);
	return (1);
}

int				ft_exebin(char *path, char **av, char **env)
{
	if (access(path, F_OK | X_OK) != -1 && ft_strchr(path, '/'))
	{
		ft_exebin_fork(path, av, env);
		return (1);
	}
	else if (ft_strchr(path, '/'))
		return (PATH_NOT_FOUND);
	else
		return (ft_exe_bin_path(path, av));
	(void)env;
}
