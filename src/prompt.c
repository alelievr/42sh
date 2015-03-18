/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:39:32 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/18 17:41:01 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_operate				*ft_parse(char *cmd)
{
	ft_putchar('\n');
	if (cmd == NULL)
		return (NULL);
	return ((t_operate *)0x1);
}

void					ft_prompt(void)
{
	t_operate			*op;

	while (42)
	{
		op = ft_parse(get_command());
		if (op == NULL)
			break ;
	}
}
