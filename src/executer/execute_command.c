/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:16:13 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/02 21:26:27 by alelievr         ###   ########.fr       */
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

#define CLOSE_PIPE(x)	close(x[0]); close(x[1]);
#define FORK_FAILED_CLOSE_PIPE(x, c) { exe_destroy_command_pipes(x, c); ft_printf("failed to fork !\n"); return (COMMAND_FAILED); }
static int			exe_create_pipes_fork(t_command *c)
{
	t_command	*begin;
	t_pipe	*pipes;
	pid_t	pid;

//	char    *bin[] = {"/bin/ls", "/bin/cat", "/bin/cat"};
//	char    *av[][3] = {{"ls", NULL}, {"cat", "-e", NULL}, {"cat", "-e", NULL}};

	int		i;

	begin = c;

	i = 0;
	pipes = exe_create_command_pipes(c);

	while (c)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i)
			{
				close(pipes[i - 1].fd[PIPE_WRITE]);
				dup2(pipes[i - 1].fd[PIPE_READ], STDIN_FILENO);
				close(pipes[i - 1].fd[PIPE_READ]);
			}
			if (c->next)
			{
				close(pipes[i].fd[PIPE_READ]);
				dup2(pipes[i].fd[PIPE_WRITE], STDOUT_FILENO);
				close(pipes[i].fd[PIPE_WRITE]);
			}
			execute_operator(c->list, c, P_CHILD);
			//exit(execv(bin[i], av[i]));
			exit(execute_binary(c->list->bin, c->list->av_bin, g_env));
		}
		execute_operator(c->list, c, P_FATHER);
		exe_add_running_pid(pid);
		if (i)
		{
			close(pipes[i - 1].fd[PIPE_READ]);
			close(pipes[i - 1].fd[PIPE_WRITE]);
		}
		c = c->next;
		i++;
	}

	int		res;
	exe_wait_command_pid(&res);
	exe_remove_running_pids();
	exe_destroy_command_pipes(pipes, begin);

/*
 	pid[0] = fork();
	if (pid[0] == 0)
	{
		//first child

		close(pipes[0].fd[PIPE_READ]);
		dup2(pipes[0].fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipes[0].fd[PIPE_WRITE]);
		exit(execv(bin[0], av[0]));
	}



	pid[1] = fork();
	if (pid[1] == 0)
	{
		//second child

		close(pipes[1].fd[PIPE_READ]);
		dup2(pipes[1].fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipes[1].fd[PIPE_WRITE]);
		close(pipes[0].fd[PIPE_WRITE]);
		dup2(pipes[0].fd[PIPE_READ], STDIN_FILENO);
		close(pipes[0].fd[PIPE_READ]);
		exit(execv(bin[1], av[1]));
	}

	close(pipes[0].fd[PIPE_READ]);
	close(pipes[0].fd[PIPE_WRITE]);

	pid[2] = fork();
	if (pid[2] == 0)
	{
		//third child
		close(pipes[1].fd[PIPE_WRITE]);
		dup2(pipes[1].fd[PIPE_READ], STDIN_FILENO);
		close(pipes[1].fd[PIPE_READ]);
		exit(execv(bin[2], av[2]));
	}

	close(pipes[1].fd[PIPE_WRITE]);
	close(pipes[1].fd[PIPE_READ]);*/

	//father:

//	waitpid(pid[0], ret + 0, 0);
//	waitpid(pid[1], ret + 1, 0);
//	waitpid(pid[2], ret + 2, 0);

//	printf("ret = %i/%i/%i\n", ret[0], ret[1], ret[2]);
//	int res = 0;
	/*	pid_t			pid;
	int				res;
	t_command		*prev;
	t_pipe			*pipes;
	const t_command	*begin = c;

	INIT(int, i, 0);
	if ((pipes = exe_create_command_pipes(c)) == (void *)COMMAND_FAILED)
		EXECUTER_ERROR("can't create pipe !\n");
	prev = NULL;
	while (c != NULL)
	{
		if ((pid = fork()) == -1)
			FORK_FAILED_CLOSE_PIPE(pipes, (t_command *)begin);
		if (pid == 0)
			exe_child_operator(c, prev, pipes + i);
		else
		{
//			printf("created pid for %s: %i\n", c->list->bin, pid);
			execute_operator(c->list, c, P_FATHER);
			exe_add_running_pid(pid);
		}
		++i;
		prev = c;
		c = c->next;
	}
	//exe_destroy_command_pipes(pipes, (t_command *)begin);
	res = 0;*/
//	if (exe_wait_command_pid(&res) == S_RUNNING)
//		;
	//exe_remove_running_pids();
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
