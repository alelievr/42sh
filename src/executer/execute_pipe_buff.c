/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_buff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 15:50:40 by alelievr          #+#    #+#             */
/*   Updated: 2016/11/26 15:53:51 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <poll.h>

void			exe_io_buff_pipe_read_write(t_command *c, t_pprocess *pp)
{
	char			buff[0xF000 + 1];
	int				ret;
	int				npipes;
	struct pollfd	fds[MAX_PIPE_COMMAND];
	size_t			i;

	i = -1;
	while (++i < pp[0].npipes)
	{
		fds[i].fd = pp[i].pipe.fd[PIPE_READ];
		fds[i].events = POLLIN;
	}
	npipes = pp[0].npipes;
//	printf("npipes = %i\n", npipes);
	if (npipes > 0)
	{
		if ((ret = poll(fds, npipes, 100)) == -1)
			perror("poll");
		if (ret == 0)
		{
			printf("poll timeout !\n");
			return ;
		}
		i = -1;
		while (++i < pp[0].npipes)
		{
			if (fds[i].revents & POLLIN)
			{
//				printf("reading on %i\n", pp[i].pipe.fd[PIPE_READ]);
				ret = read(pp[i].pipe.fd[PIPE_READ], buff, sizeof(buff) - 1);
				if (ret > 0)
				{
					buff[ret] = 0;
//					printf("buff = %s\n", buff);
					write(pp[i].pipe.fd_buff[PIPE_WRITE], buff, ret);
					if (pp[i].process.status != S_RUNNING)
					{
//						printf("closing pipe because process is terminated\n");
						pp[i].pipe.open = 0;
						close(pp[i].pipe.fd[PIPE_READ]);
						close(pp[i].pipe.fd_buff[PIPE_WRITE]);
					}
				}
				if (ret == 0)
				{
//					printf("closing pipe !\n");
					close(pp[i].pipe.fd[PIPE_READ]);
					close(pp[i].pipe.fd_buff[PIPE_WRITE]);
				}
				if (ret == -1)
					;
			}
			else
				printf("nothing to read on %i\n", pp[i].pipe.fd[PIPE_READ]);
		}
		//	perror("read on pipe");
	}
	(void)c;
/*	int		i;
	int		npipes;
	int		ret;

	i = -1;
	npipes = exe_get_pipe_number(c);
	if (npipes > 0)
		while (++i < npipes)
		{
			if ((ret = read(pipes[i].fd[PIPE_READ], pipes[i].buff, PIPE_BUFF_SIZE)))
			{
				puts("pipe content:");
				write(1, pipes[i].buff, ret);
				if (write(pipes[i].fd_buff[PIPE_WRITE], pipes[i].buff, ret) == -1)
					perror("write on pipe");
			}
			if (ret == -1)
				perror("read on pipe");
		}*/
}
