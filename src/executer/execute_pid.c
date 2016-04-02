/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:30:41 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/02 20:10:45 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <sys/wait.h>

static pid_t	*exe_get_pid_list(void)
{
	static pid_t		pid_list[MAX_PIPE_COMMAND + 2] = {P_LIST_END};

	return (pid_list);
}

int				exe_wait_command_pid(int *ret)
{
	pid_t		*pid_list = exe_get_pid_list();
	int			i;

	i = 0;
	printf("waiting ...\n");
	while (*pid_list != P_LIST_END && i < MAX_PIPE_COMMAND)
	{
		printf("waiting for pid: %i\n", *pid_list);
		waitpid(*pid_list++, ret, WCONTINUED);
	}
	printf("terminated !\n");
	return (S_TERMINATED);
}

void			exe_add_running_pid(pid_t pid)
{
	pid_t		*pid_list = exe_get_pid_list();
	int			i;

	i = 0;
	while (*pid_list != P_LIST_END && i < MAX_PIPE_COMMAND)
	{
		pid_list++;
		i++;
	}
	if (i == MAX_PIPE_COMMAND)
		return ;
	*pid_list = pid;
	*(pid_list + 1) = P_LIST_END;
}

void			exe_remove_running_pids(void)
{
	pid_t		*pid_list = exe_get_pid_list();

	*pid_list = P_LIST_END;
}
