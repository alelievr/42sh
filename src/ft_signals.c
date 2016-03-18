/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 01:11:47 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/18 02:37:43 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <signal.h>

void		siguser_handler(int s)
{
	pid_t		fg;

	if ((fg = get_fg_pid(0)) != -1)
	{
		printf("sending sig %i to %i\n", s, fg);
		kill(fg, s);
		if (s == SIGTSTP)
			add_bg_pid(fg);
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
