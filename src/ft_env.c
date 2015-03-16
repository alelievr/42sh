/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:37:06 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/16 17:06:56 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

#include <stdio.h>
int			ft_env(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac <= 1)
		while (g_env[i])
			ft_putendl(g_env[i++]);
	(void)av;
	return (0);
}
