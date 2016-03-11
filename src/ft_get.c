/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 17:49:44 by alelievr          #+#    #+#             */
/*   Updated: 2015/04/03 23:26:21 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			ft_get(int ac, char **av)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i < ac)
	{
		tmp = get_var(av[i]);
		if (tmp)
			ft_putendl(tmp);
		else
			ft_printf("%s not set !\n", av[i]);
		i++;
	}
	return (0);
}
