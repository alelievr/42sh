/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 20:12:34 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/02 02:03:39 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int				exe_get_stdout(int fd)
{
	static int		stdout_fd = -1;

	if (fd != -1)
		stdout_fd = fd;
	return (stdout_fd);
}

int				exe_stdout_to_pipe(t_command *c)
{
	if (close(c->pipe.fd[PIPE_READ]) == -1)
		EXECUTER_ERROR("failed to close pipe !\n");
	if (dup2(c->pipe.fd[PIPE_WRITE], STDOUT_FILENO) == -1)
		EXECUTER_ERROR("failed to dup2 stdout to pipe !\n");
	if (close(c->pipe.fd[PIPE_WRITE]) == -1)
		EXECUTER_ERROR("failed to close pipe !\n");
	return (COMMAND_OK);
}

int				exe_stdin_from_pipe(t_command *prev)
{
	if (close(prev->pipe.fd[PIPE_WRITE]) == -1)
		EXECUTER_ERROR("failed to close pipe !\n");
	if (dup2(prev->pipe.fd[PIPE_READ], STDIN_FILENO) == -1)
		EXECUTER_ERROR("failed to dup2 stdin to pipe !\n");
	if (close(prev->pipe.fd[PIPE_READ]) == -1)
		EXECUTER_ERROR("failed to close pipe !\n");
	return (COMMAND_OK);
}
