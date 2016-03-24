/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:39:32 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/18 23:06:19 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_operate				*create_op_redir(char **cmd, int len, int type)
{
	t_operate	*op;

	op = (t_operate *)malloc(sizeof(t_operate));
	op->type = type;
	op->value = cmd;
	(void)cmd;
	(void)len;
	return (op);
}

void					exec_command(char *cmd)
{
	char				**tmp;
	int					r;

	tmp = NULL;
	//TODO: parse the cmd to t_commandline *
	//TODO: execute the t_commandline *

	printf("\ncmd = [%s]\n", cmd);
	tmp = preparse_command(cmd);
	if (tmp)
		if (!ft_builtins(tmp))
		{
			if (!(r = ft_exebin(tmp[0], tmp, g_env)))
				ft_printf("%s: command not found !\n", tmp[0]);
			else if (r == PATH_NOT_FOUND)
				ft_printf("%s: binary not found !\n", tmp[0]);
		}
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
