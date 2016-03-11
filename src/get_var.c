/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 23:23:44 by alelievr          #+#    #+#             */
/*   Updated: 2015/04/03 23:23:45 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char	*get_var(char *name)
{
	int		i;

	i = 0;
	while (g_var[i])
	{
		if (!ft_strncmp(name, g_var[i], ft_strlen(name))
				&& g_var[i][ft_strlen(name)] == '=')
			return (g_var[i] + ft_strlen(name) + 1);
		i++;
	}
	return (NULL);
}
