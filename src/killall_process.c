/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killall_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 23:04:02 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/19 16:39:25 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <signal.h>

void		killall_bg_process(void)
{
	t_process		*p;

	while ((p = get_last_bg_pid()) != NULL)
	{
		kill(p->pid, SIGKILL);
		delete_last_bg_pid();
	}
}
