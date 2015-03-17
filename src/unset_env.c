/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 21:21:48 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/17 17:06:22 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			unset_env(char *name)
{
	int		i;

	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(name, g_env[i], ft_strlen(name)) &&
				g_env[i][ft_strlen(name)] == '=')
		{
			free(g_env[i++]);
			while (g_env[i])
			{
				g_env[i - 1] = g_env[i];
				i++;
			}
			g_env[i - 1] = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}
