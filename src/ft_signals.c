/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 01:11:47 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/19 16:38:48 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <signal.h>

void		siguser_handler(int s)
{
	t_process	*fg;

	if ((fg = get_fg_pid(0, NULL, 0)) != NULL)
	{
//		setpgid(fg->pid, getpid());
		if (kill(fg->pid, s) == -1)
			perror("kill");
		if (s == SIGTSTP)
			add_bg_pid(fg->pid, fg->name, S_STOPPED);
//		setpgid(fg, fg);
	}
}

void		ft_signals(void)
{
	signal(SIGINT, siguser_handler);
	signal(SIGTERM, siguser_handler);
	signal(SIGKILL, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
	signal(SIGTSTP, siguser_handler);
	signal(SIGQUIT, siguser_handler);
}
