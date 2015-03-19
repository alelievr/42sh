/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 21:20:22 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/19 13:46:44 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

#include <stdio.h>
int			ft_setenv(int ac, char **av)
{
	char	*name;
	char	*value;
	char	*tmp;

	ac--;
	while (ac > 0)
	{
		if ((tmp = ft_strchr(av[ac], '=')) != NULL)
		{
			value = tmp + 1;
			name = av[ac];
			ft_printf("name = %s\nvalue = %s\n", name, value);
			*tmp = '\0';
			set_env(name, value);
		}
		ac--;
	}
	return (1);
}
