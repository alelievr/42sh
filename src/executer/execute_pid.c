/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:30:41 by alelievr          #+#    #+#             */
/*   Updated: 2016/05/26 18:49:23 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <sys/wait.h>
#include <signal.h>

t_pprocess		*exe_init_pid_list(t_pprocess *p)
{
	static t_pprocess	*pp = NULL;

	if (p)
		pp = p;
	return (pp);
}

int				exe_wait_command_pid(int *ret)
{
	t_pprocess	*pp = exe_init_pid_list(NULL);
	size_t		i;
	size_t		npipes;	

	i = 0;
	npipes = pp->npipes;
	while (pp && i <= pp[0].npipes && pp[i].process.pid != 0)
	{
		printf("checking wait for: %i\n", pp[i].process.pid);
		if (pp[i].process.status == S_RUNNING &&
				waitpid(pp[i].process.pid, ret, WCONTINUED | WNOHANG))
		{
			pp[i].process.status = S_TERMINATED;
			printf("%i terminated !\n", pp[i].process.pid);
			if (pp[0].npipes != 0)
			{
				if (pp[i].pipe.open)
				{
//					close(pp[i].pipe.fd[PIPE_WRITE]);
//					close(pp[i].pipe.fd[PIPE_READ]);
//					close(pp[i].pipe.fd_buff[PIPE_WRITE]);
//					close(pp[i].pipe.fd_buff[PIPE_READ]);
//					printf("closed pipe n %zu!\n", i);
				}
				//...
			}
		}
		else if (pp[i].process.status == S_RUNNING)
			return (S_RUNNING);
		i++;
	}
	return (S_TERMINATED);
}

void			exe_add_running_pid(pid_t pid)
{
	t_pprocess	*pp = exe_init_pid_list(NULL);
	size_t		i;

	i = 0;
	if (pp)
		while (i <= pp[0].npipes && pp[i].process.pid != 0)
			i++;
	if (i > pp[0].npipes + 1)
		return ;
	printf("added pid: %i at index %zu\n", pid, i);
	pp[i].process.pid = pid;
	pp[i].process.status = S_RUNNING;
}

void			exe_remove_running_pids(void)
{
	t_pprocess	*pp = exe_init_pid_list(NULL);
	size_t		i;

	i = 0;
	if (pp)
		while (i <= pp[0].npipes && pp[i].process.pid != 0)
		{
			pp[i].process.pid = 0;
			i++;
		}
}

void			exe_send_sig_pids(int s)
{
	t_pprocess	*pp = exe_init_pid_list(NULL);
	size_t		i;

	i = 0;
	if (pp)
		while (i <= pp[0].npipes && pp[i].process.pid != 0)
		{
			kill(pp[i].process.pid, s);
			i++;
		}
}
