/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 21:08:56 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/16 00:39:53 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_builtins	g_builts[] = {
	{"env", ft_env},
	{"unsetenv", ft_unsetenv},
	{"setenv", ft_setenv},
	{"cd", ft_cd},
	{"exit", ft_exit},
	{"echo", ft_echo},
	{"getenv", ft_getenv},
	{"set", ft_set},
	{"unset", ft_unset},
	{"get", ft_get},
	{"bonus", ft_bonus},
	{"fg", ft_fg},
	{"bg", ft_bg},
	{"history", ft_history},
	{NULL, NULL}
};

int			ft_builtins(char **com)
{
	int		i;
	int		ac;
	int		ret;

	ret = 0;
	ac = 0;
	while (com[ac])
		ac++;
	i = 0;
	while (g_builts[i].name)
	{
		if (!ft_strcmp(*com, g_builts[i].name) && ((ret = 1)))
		{
			g_builts[i].fun(ac, com);
			break ;
		}
		i++;
	}
	return (ret);
}
