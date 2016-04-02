/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:30:41 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/03 01:24:30 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <sys/wait.h>
#include <signal.h>

static t_process	*exe_get_pid_list(void)
{
	static t_process	pid_list[MAX_PIPE_COMMAND + 2] = {{P_LIST_END, 0, 0, 0}};

	return (pid_list);
}

int				exe_wait_command_pid(int *ret)
{
	t_process	*pid_list = exe_get_pid_list();
	int			i;

	i = 0;
	while ((*pid_list).pid != P_LIST_END && i < MAX_PIPE_COMMAND)
	{
		if (waitpid((*pid_list).pid, ret, WCONTINUED | WNOHANG))
			(*pid_list).status = S_TERMINATED;
		else
			return (S_RUNNING);
		pid_list++;
	}
	return (S_TERMINATED);
}

void			exe_add_running_pid(pid_t pid)
{
	t_process		*pid_list = exe_get_pid_list();
	int			i;

	i = 0;
	while ((*pid_list).pid != P_LIST_END && i < MAX_PIPE_COMMAND)
	{
		pid_list++;
		i++;
	}
	if (i == MAX_PIPE_COMMAND)
		return ;
	(*pid_list).pid = pid;
	(*(pid_list + 1)).pid = P_LIST_END;
}

void			exe_remove_running_pids(void)
{
	t_process	*pid_list = exe_get_pid_list();

	(*pid_list).pid = P_LIST_END;
}

void			exe_send_sig_pids(int s)
{
	t_process	*pid_list = exe_get_pid_list();
	int			i;

	i = 0;
	while ((*pid_list).pid != P_LIST_END && i < MAX_PIPE_COMMAND)
	{
		kill((*pid_list).pid, s);
		pid_list++;
		i++;
	}
}
