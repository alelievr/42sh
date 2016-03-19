/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killall_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 23:04:02 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/18 23:07:18 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <signal.h>

void		killall_bg_process(void)
{
	pid_t		pid;

	while ((pid = get_last_bg_pid()) != -1)
	{
		kill(pid, SIGKILL);
		delete_last_bg_pid();
	}
}
