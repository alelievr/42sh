/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:39:32 by fdaudre-          #+#    #+#             */
/*   Updated: 2017/01/16 12:07:46 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void					exec_command(char *cmd)
{
	char				**pre;
	int					r;
	t_commandline		*cmdline;

	//TODO: execute the t_commandline *

	printf("\ncmd = [%s]\n", cmd);
	if (!(pre = preparse_command(cmd)))
		return ;
	r = -1;
	printf("parser:\n");
	while (pre[++r])
		printf("[%02i]: %s\n", r, pre[r]);
	if (!(cmdline = ft_lex(pre)))
	{
		printf("null lex !\n");
		return ;
	}
	print_cmd_line(cmdline);
	executer(cmdline);
}

void					ft_prompt(void)
{
	static t_prompt		d;
	char				*cmd;
	struct winsize		ws;

	if (ioctl(0, TIOCGWINSZ, &ws) != -1 && get_env("TERM"))
		d.good_prompt = 1;
	load_history(&d);
	get_current_prompt(&d);
	while (42)
	{
		cmd = get_command(&d);
		if (cmd)
			exec_command(cmd);
		else
		{
			write(1, "\n", 1);
			break ;
		}
	}
	write_history(&d);
	killall_bg_process();
}
