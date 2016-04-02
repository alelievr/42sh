/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 20:12:34 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/02 23:06:49 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_pipe		*exe_create_command_pipes(t_command *c)
{
	int		npipes;
	t_pipe	*ret;

	npipes = exe_get_pipe_number(c);
	printf("npipes = %i\n", npipes);
	if (npipes > 0)
	{
		ret = malloc(sizeof(t_pipe) * npipes);
		while (npipes--)
		{
			if (pipe(ret[npipes].fd) == -1)
			{
				ft_printf("can't create pipe !\n");
				return (void *)COMMAND_FAILED;
			}
			ret[npipes].open = 1;
		}
		return (ret);
	}
	return ((t_pipe *)0x0);
}

void			exe_destroy_command_pipes(t_pipe *pipes, t_command *c)
{
	int		npipes;

	npipes = exe_get_pipe_number(c);
	if (npipes > 0)
	{
		while (npipes--)
		{
			close(pipes[npipes].fd[0]);
			close(pipes[npipes].fd[1]);
		}
		free(pipes);
	}
}

int				exe_get_stdout(int fd)
{
	static int		stdout_fd = -1;

	if (fd != -1)
		stdout_fd = fd;
	return (stdout_fd);
}

int				exe_stdout_to_pipe(t_pipe *p)
{
	if (close(p->fd[PIPE_READ]) == -1)
		EXECUTER_ERROR("failed to close pipe !\n");
	if (dup2(p->fd[PIPE_WRITE], STDOUT_FILENO) == -1)
		EXECUTER_ERROR("failed to dup2 stdout to pipe !\n");
	if (close(p->fd[PIPE_WRITE]) == -1)
		EXECUTER_ERROR("failed to close pipe !\n");
	return (COMMAND_OK);
}

int				exe_stdin_from_pipe(t_pipe *p)
{
	if (close(p->fd[PIPE_WRITE]) == -1)
		EXECUTER_ERROR("failed to close pipe !\n");
	if (dup2(p->fd[PIPE_READ], STDIN_FILENO) == -1)
		EXECUTER_ERROR("failed to dup2 stdin to pipe !\n");
	if (close(p->fd[PIPE_READ]) == -1)
		EXECUTER_ERROR("failed to close pipe !\n");
	return (COMMAND_OK);
}
