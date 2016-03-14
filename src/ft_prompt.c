/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:39:32 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/11 18:21:38 by alelievr         ###   ########.fr       */
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

void					ft_prompt(void)
{
	char		buff[0xF00];
	int			r;
	char		**tmp;
	char		*tmp2;
	t_prompt	d;

	load_history(&d);
	while (42)
	{
		tmp = NULL;
		tmp2 = get_command(&d);
		//TODO: parse the cmd to t_commandline *
		//TODO: execute the t_commandline *
		printf("cmd = [%s]\n", tmp2);
	//	tmp2 = ft_strjoin("env -i ", tmp2);
		if (tmp2)
		{
			if (!*tmp2)
				continue ;
			tmp = ft_strsplit(tmp2, " \t\f\v\r\n");
			if (tmp && tmp[0])
				if (!ft_builtins(tmp))
				{
					if (!(r = ft_exebin(tmp[0], tmp, g_env)))
						ft_printf("%s: command not found !\n", tmp[0]);
					else if (r == PATH_NOT_FOUND)
						ft_printf("%s: binary not found !\n", tmp[0]);
				}
		}
		else
			break ;
	}
	write_history(&d);
	/*
	t_operate			*op;
	t_operate			*tmp;

	char	**v1 = (char **)malloc(sizeof(char *) * 3);
	char	**v2 = (char **)malloc(sizeof(char *) * 3);
	v1[0] = "end";
	v1[1] = NULL;
	v2[0] = "cat";
	v2[1] = "-e";
	v2[2] = NULL;
	op = create_op_redir(v1, 1, DREDIR_L);
	op->next = create_op_redir(v2, 1, BIN);
	op->next->next = NULL;
	execute_command(op);
	(void)tmp;
	(void)op;*/
	(void)buff;
	(void)r;
}
