/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 20:12:34 by alelievr          #+#    #+#             */
/*   Updated: 2016/05/27 01:00:58 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <fcntl.h>

t_pprocess	*exe_create_command_pipes(t_command *c)
{
	int			npipes;
	int			npipes_const;
	t_pprocess	*ret;
//	int			flags;

	ret = NULL;
	npipes = exe_get_pipe_number(c);
	npipes_const = npipes;
	if (npipes > 0)
	{
		ret = (t_pprocess *)malloc(sizeof(t_pprocess) * (npipes + 1));
		ret[npipes].process = (t_process){0, NULL, S_UNDEFINED, NULL};
		ret[npipes].pipe.open = 0;
		ret[npipes].npipes = 0;
		while (npipes--)
		{
			if (pipe(ret[npipes].pipe.fd) == -1)
			{
				ft_printf("can't create pipe !\n");
				return (void *)COMMAND_FAILED;
			}
			if (pipe(ret[npipes].pipe.fd_buff) == -1)
			{
				ft_printf("can't create pipe !\n");
				return (void *)COMMAND_FAILED;
			}
			ret[npipes].pipe.open = 1;
			ret[npipes].process = (t_process){0, NULL, S_UNDEFINED, NULL};
			ret[npipes].id = npipes;
			ret[npipes].npipes = npipes_const;
		}
	}
	else
	{
		ret = (t_pprocess *)malloc(sizeof(t_pprocess) * 1);
		ret->process = (t_process){0, NULL, S_UNDEFINED, NULL};
		ret->npipes = 0;
		ret->id = 0;
	}
	return (ret);
}

void			exe_destroy_command_pipes(t_pprocess *pp)
{
	int		npipes;

	npipes = pp->npipes;
	if (npipes > 0)
	{
		while (npipes--)
		{
			close(pp[npipes].pipe.fd[0]);
			close(pp[npipes].pipe.fd[1]);
			close(pp[npipes].pipe.fd_buff[0]);
			close(pp[npipes].pipe.fd_buff[1]);
		}
	}
	free(pp);
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
	if (close(p->fd_buff[PIPE_WRITE]) == -1)
		EXECUTER_ERROR("failed to close buff pipe !\n");
	if (dup2(p->fd_buff[PIPE_READ], STDIN_FILENO) == -1)
		EXECUTER_ERROR("failed to dup2 stdin to buff pipe !\n");
	if (close(p->fd_buff[PIPE_READ]) == -1)
		EXECUTER_ERROR("failed to close buff pipe !\n");
	return (COMMAND_OK);
}
