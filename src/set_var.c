/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:02:21 by alelievr          #+#    #+#             */
/*   Updated: 2015/04/03 23:22:49 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

#define SC sizeof(char)

static void set_loc_var(char *name, char *value, int i)
{
	if (!(g_var[i] = malloc(SC * (ft_strlen(name) + ft_strlen(value) + 2))))
		m_error();
	strcpy(g_var[i], name);
	strcat(g_var[i], "=");
	strcat(g_var[i], value);
}

int			set_var(char *name, char *value)
{
	int     i;

	i = 0;
	while (g_var[i])
	{
		if (!ft_strncmp(g_var[i], name, ft_strlen(name))
				&& g_var[i][ft_strlen(name)] == '=')
		{
			set_loc_var(name, value, i);
			return (0);
		}
		i++;
	}
	if (i > MAX_VAR)
	{
		ft_putstr("Too many local variables !\n");
		return (-1);
	}
	else
		set_loc_var(name, value, i);
	g_var[i + 1] = NULL;
	return (0);
}
