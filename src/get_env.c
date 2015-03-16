/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 16:51:27 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/16 16:41:54 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char	*get_env(char *name)
{
	int		i;

	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(name, g_env[i], ft_strlen(name)))
			return (g_env[i] + ft_strlen(name) + 1);
		i++;
	}
	return (NULL);
}
