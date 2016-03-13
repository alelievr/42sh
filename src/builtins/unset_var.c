/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:11:54 by alelievr          #+#    #+#             */
/*   Updated: 2015/04/03 23:12:32 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			unset_var(char *name)
{
	int		i;

	i = 0;
	while (g_var[i])
	{
		if (!ft_strncmp(name, g_var[i], ft_strlen(name)) &&
				g_var[i][ft_strlen(name)] == '=')
		{
			free(g_var[i++]);
			while (g_var[i])
			{
				g_var[i - 1] = g_var[i];
				i++;
			}
			g_var[i - 1] = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}
