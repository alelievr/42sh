/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 21:20:22 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/17 18:01:51 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

#include <stdio.h>
int			ft_setenv(int ac, char **av)
{
	char	*name;
	char	*value;

	ac--;
	while (ac > 0)
	{
		if (ft_firstocc(av[ac], '=') != -1)
		{
			value = &av[ac][ft_firstocc(av[ac], '=') + 1];
			name = av[ac];
			printf("name = %s\nvalue = %s\n", name, value);
			av[ac][ft_firstocc(av[ac], '=')] = 0;
			set_env(name, value);
		}
		ac--;
	}
	return (1);
}
