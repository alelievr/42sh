/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:16:13 by alelievr          #+#    #+#             */
/*   Updated: 2016/05/25 17:45:47 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <time.h>

static int			check_executable(char *name)
{
	if (!name)
		return (BINARY_NOT_FILE);
	if (access(name, F_OK) == 0 && !is_dir(name))
	{
		if (access(name, X_OK) == 0)
			return (BINARY_OK);
		else
			return (BINARY_NOT_EXECUTABLE);
	}
	else if (is_builtin(name))
		return (BINARY_OK);
	else if (get_binhash_path(hashstring(name)))
		return (BINARY_OK);
	else
		return (BINARY_NOT_IN_PATH);
	return (BINARY_NOT_FILE);
}

static int			check_command_executables(t_command *c, int print)
{
	size_t		i;
	int			r;

	i = -1;
	while (c)
	{
		if (!c->list || ((r = check_executable(c->list->bin))))
		{
			if ((r == BINARY_NOT_FILE || r == BINARY_NOT_IN_PATH) && print)
				ft_printf("%s: command not found\n", c->list->bin);
			else if (r == BINARY_NOT_EXECUTABLE && print)
				ft_printf("%s: can't execute file\n", c->list->bin);
			return (COMMAND_FAILED);
		}
		c = c->next;
	}
	return (COMMAND_OK);
}

int			exe_child_operator(t_command *c, t_command *prev, t_pipe *p)
{
	if (c->next)
	{
		printf("stdout to pipe for %s\n", c->list->bin);
		exe_stdout_to_pipe(p);
	}
	if (prev)
	{
		printf("stdin to pipe for %s\n", c->list->bin);
		exe_stdin_from_pipe(p - 1);
	}
	execute_operator(c->list, c, P_CHILD);
	exit(execute_binary(c->list->bin, c->list->av_bin, g_env));
}

#define FORK_FAILED_CLOSE_PIPE(x) { exe_destroy_command_pipes(x); ft_printf("failed to fork !\n"); return (COMMAND_FAILED); }
static int			exe_create_pipes_fork(t_command *c)
{
	t_command	*begin;
	t_pprocess	*pipes;
	pid_t	pid;

//	char    *bin[] = {"/bin/ls", "/bin/cat", "/bin/cat"};
//	char    *av[][3] = {{"ls", NULL}, {"cat", "-e", NULL}, {"cat", "-e", NULL}};

	int		i;

	begin = c;

	i = 0;
	if ((pipes = exe_create_command_pipes(c)) == (void*)COMMAND_FAILED)
		return (COMMAND_FAILED);

	exe_init_pid_list(pipes);
	while (c)
	{
		if ((pid = fork()) == -1)
			exit(ft_printf(("can't fork anymore !\n")));
		if (pid == 0)
		{
			if (i)
				if (exe_stdin_from_pipe(&(pipes[i - 1].pipe)) == COMMAND_FAILED)
					exit(COMMAND_FAILED);
			if (c->next)
				if (exe_stdout_to_pipe(&(pipes[i].pipe)) == COMMAND_FAILED)
					exit(COMMAND_FAILED);
			//execute_operator(c->list, c, P_CHILD);
			//exit(execv(bin[i], av[i]));
			exit(execute_binary(c->list->bin, c->list->av_bin, g_env));
		}
//		execute_operator(c->list, c, P_FATHER);
		exe_add_running_pid(pid);
		if (i)
		{
//			close(pipes[i - 1].fd[PIPE_READ]);
			close(pipes[i - 1].pipe.fd[PIPE_WRITE]);
			close(pipes[i - 1].pipe.fd_buff[PIPE_READ]);
		}
		c = c->next;
		i++;
	}

	int					res;
	struct timespec		sleep;
	sleep.tv_sec = 0;
	sleep.tv_nsec = 1000000;
	while (exe_wait_command_pid(&res) == S_RUNNING)
	{
		exe_io_buff_pipe_read_write(begin, pipes);
		nanosleep(&sleep, NULL);
		printf("executing ...\n");
	}
//	exe_send_sig_pids(SIGKILL);
	exe_remove_running_pids();
	exe_destroy_command_pipes(pipes);
	return (res);
}

int					execute_command(t_command *c)
{
	if (check_command_executables(c, 1))
		return (COMMAND_FAILED);
	return (exe_create_pipes_fork(c));
}
