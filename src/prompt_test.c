/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:39:32 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/20 11:53:45 by alelievr         ###   ########.fr       */
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

	char	**v1 = (char **)malloc(sizeof(char *) * 3);
	char	**v2 = (char **)malloc(sizeof(char *) * 3);
	v1[0] = "t1";
	v1[1] = NULL;
	v2[0] = "cat";
	v2[1] = NULL;
	op = create_op_redir(v1, 1, REDIR_L);
	op->next = create_op_redir(v2, 1, BIN);
	op->next->next = NULL;
	execute_command(op);
	(void)tmp;
	(void)op;
}
