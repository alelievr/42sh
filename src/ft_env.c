/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:37:06 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/17 17:08:18 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static char	**ft_env_cpy(char **new_env)
{
	int		i;

	i = 0;
	while (g_env[i])
	{
		new_env[i] = ft_strdup(g_env[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

static char	**ft_add_env(char **new_env, char *str)
{
	int		i;

	i = 0;
	while (new_env[i])
		i++;
	new_env[i++] = ft_strdup(str);
	new_env[i] = NULL;
	return (new_env);
}

static void	ft_print_env(char **env)
{
	while (*env)
		ft_putendl(*env++);
}

int			ft_env(int ac, char **av)
{
	int		i;
	char	**new_env;
	i = 0;
	if (ac <= 1)
		while (g_env[i])
			ft_putendl(g_env[i++]);
	else if (ac >= 2)
	{
		i = 1;
		new_env = (char **)malloc(sizeof(char *) * MAX_ENV);
		if (av[1][0] == '-')
		{
			if (ft_strcmp(av[1], "-i"))
			{
				ft_putstr("env illegal option -- ");
				ft_putchar(av[1][1]);
				ft_putstr("\nusage: env [-i] [name=value ...] "
						"[utility [argument ...]]");
				return (0);
			}
			else
				i++;
		}
		else
			new_env = ft_env_cpy(new_env);
		while (av[i] && ft_strchr(av[i], '='))
		{
			new_env = ft_add_env(new_env, av[i]);
			i++;
		}
		if (av[i])
			ft_exebin(av[i], &av[1], new_env);
		else
			ft_print_env(new_env);
		free(new_env);
	}
	(void)av;
	return (0);
}
