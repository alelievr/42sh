/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 00:35:35 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/25 19:11:25 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			ft_history(int ac, char **av)
{
	t_list	*hs;
	size_t	max;
	size_t	i;

	if (av[1])
		max = ft_atoi(av[1]);
	else
		max = 20;
	if (max > 5000)
		return (ft_printf("too large number !\n"));
	hs = get_history_list(NULL);
	i = 0;
	while (max-- && hs)
	{
		ft_printf("%02i %s\n", i++, hs->content);
		hs = hs->next;
	}
	(void)ac;
	return (1);
}
