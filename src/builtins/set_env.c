/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:02:34 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/17 17:10:45 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#define SC sizeof(char)

static void	set_var_env(char *name, char *value, int i)
{
	if (!(g_env[i] = malloc(SC * (ft_strlen(name) + ft_strlen(value) + 2))))
		m_error();
	strcpy(g_env[i], name);
	strcat(g_env[i], "=");
	strcat(g_env[i], value);
	if (!ft_strcmp(name, "PATH"))
	{
		delete_binhash();
		load_binhash();
	}
}

int			set_env(char *name, char *value)
{
	int		i;

	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(g_env[i], name, ft_strlen(name))
				&& g_env[i][ft_strlen(name)] == '=')
		{
			set_var_env(name, value, i);
			return (0);
		}
		i++;
	}
	if (i > MAX_ENV)
	{
		ft_putstr("Too many environement variables !\n");
		return (-1);
	}
	else
		set_var_env(name, value, i);
	g_env[i + 1] = NULL;
	return (0);
}
