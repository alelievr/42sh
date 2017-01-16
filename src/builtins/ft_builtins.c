/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 21:08:56 by alelievr          #+#    #+#             */
/*   Updated: 2016/11/26 16:35:38 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_builtins	g_builts[] = {
	{"env", ft_env, true},
	{"unsetenv", ft_unsetenv, false},
	{"setenv", ft_setenv, false},
	{"cd", ft_cd, false},
	{"exit", ft_exit, false},
	{"echo", ft_echo, true},
	{"getenv", ft_getenv, true},
	{"set", ft_set, false},
	{"unset", ft_unset, false},
	{"get", ft_get, true},
	{"bonus", ft_bonus, true},
	{"fg", ft_fg, false},
	{"bg", ft_bg, false},
	{"jobs", ft_jobs, false},
	{"history", ft_history, true},
	{"alias", ft_alias, false},
	{"where", ft_where, true},
	{NULL, NULL, true}
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
			ret = 1;
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

int			is_builtin_forkable(char *s)
{
	int		i;

	i = -1;
	while (g_builts[++i].name)
		if (!ft_strcmp(g_builts[i].name, s))
			return (g_builts[i].forkable);
	return (-1);
}
