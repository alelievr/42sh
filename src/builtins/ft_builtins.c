/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 21:08:56 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/01 19:55:34 by alelievr         ###   ########.fr       */
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
	{"jobs", ft_jobs},
	{"history", ft_history},
	{"alias", ft_alias},
	{"where", ft_where},
	{NULL, NULL}
};

int			ft_builtins(char **com, int *cmdret)
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
			*cmdret = g_builts[i].fun(ac, com);
			break ;
		}
		i++;
	}
	return (ret);
}

int			is_builtin(char *s)
{
	int		i;

	i = -1;
	while (g_builts[++i].name)
		if (!ft_strcmp(g_builts[i].name, s))
			return (1);
	return (0);
}
