/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:16:13 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/02 02:12:39 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static int			check_executable(char *name)
{
	if (!name)
		return (BINARY_NOT_FILE);
	if (access(name, F_OK) == 0 && !is_dir(name))
	{
		if (access(name, X_OK))
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

static int			exe_child_operator(t_command *c, t_command *prev)
{
	if (c->next)
		exe_stdout_to_pipe(c);
	if (prev)
		exe_stdin_from_pipe(prev);
	execute_operator(c->list, c, P_CHILD);
	exit(execute_binary(c->list->bin, c->list->av_bin, g_env));
}

#define CLOSE_PIPE(x)	close(x[0]); close(x[1]);
#define FORK_FAILED_CLOSE_PIPE(x)	{CLOSE_PIPE(x); ft_printf("failed to fork !\n"); return (COMMAND_FAILED); }
static int			exe_create_pipes_fork(t_command *c)
{
	pid_t		pid;
	int			res;
	t_command	*prev;

	prev = NULL;
	while (c != NULL)
	{
		if (c->next)
			if (pipe(c->pipe.fd) == -1)
				EXECUTER_ERROR("can't create pipe !\n");
		if ((pid = fork()) == -1)
			FORK_FAILED_CLOSE_PIPE(c->pipe.fd);
		if (pid == 0)
			exe_child_operator(c, prev);
		else
			execute_operator(c->list, c, P_FATHER);
		prev = c;
		c = c->next;
	}
	res = 0;
//	while (!waitpid(pid, &res, WNOHANG))
//		printf("waiting ...\n");
//		dlog("waiting for the end ..., res = %i\n", res);
	return (res);
}

int					execute_command(t_command *c)
{
	if (check_command_executables(c, 1))
		return (COMMAND_FAILED);
	return (exe_create_pipes_fork(c));
}
