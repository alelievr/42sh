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

/*	while (42)
	{
		r = read(0, buff, 0xF00);
		buff[r - 1] = 0;
		if (buff[0])
			ft_builtins(ft_strsplit(buff, " "));
	}*/
	while (42)
	{
		tmp = NULL;
		tmp2 = get_command();
		printf("cmd = [%s]\n", tmp2);
	//	tmp2 = ft_strjoin("env -i ", tmp2);
		if (tmp2)
		{
			tmp = ft_strsplit(tmp2, " \t\f\v\r\n");
			if (tmp && tmp[0])
			{
				if (!ft_builtins(tmp))
					if (!(ft_exebin(tmp[0], tmp, g_env)))
						ft_printf("%s: command not found !\n", tmp[0]);
			}
		}
		else
			break ;
	}
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
