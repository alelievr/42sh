/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:39:32 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/18 17:47:55 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_operate				*create_op_redir(char *cmd)
{
	t_operate	*op;

	op = (t_operate *)malloc(sizeof(t_operate));
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
//		op = create_op_redir("text");
//		op->next = careta 
	}
	(void)tmp;
	(void)op;
}
