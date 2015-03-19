/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 18:40:25 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/19 22:06:10 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_exec(int ac, char **av)
{
	if (ft_builtins(av) == 0)
		ft_exebin(*av, av, g_env);
	(void)ac;
}
