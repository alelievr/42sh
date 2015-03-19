/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:39:32 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/18 22:39:51 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_operate				*create_op_redir(char **cmd, int len, int type)
{
	t_operate	*op;

	op = (t_operate *)malloc(sizeof(t_operate));
	op->type = type;
	op->value = cmd;
	op->len = len;
	(void)cmd;
	return (op);
}

void					ft_prompt(void)
{
	t_operate			*op;
	t_operate			*tmp;
	char				buff[0xF00];
	int					ret;

	while (42)
	{
		ret = read(0, buff, 0xF00 - 1);
		buff[ret - 1] = 0;
		ft_builtins(ft_strsplit(buff, ' '));
		char	**v1 = (char **)malloc(sizeof(char *) * 3);
		char	**v2 = (char **)malloc(sizeof(char *) * 3);
		v1[0] = "t1";
		v1[2] = "t2";
		v1[3] = NULL;
		v2[0] = "ls";
		v2[1] = NULL;
		op = create_op_redir(v1, 2, REDIR_R);
		op->next = create_op_redir(v2, 1, BIN);
		execute_command(op);
	}
	(void)tmp;
	(void)op;
}
