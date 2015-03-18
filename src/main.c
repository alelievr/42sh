/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:55:43 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/18 15:52:03 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <stdlib.h>

char	**g_env;

int		main(int ac, char **av, char **environ)
{
	int		i;

	i = 0;
	if (!(g_env = (char **)malloc(sizeof(char *) * MAX_ENV)))
		m_error();
	i = 0;
	while (*environ)
		g_env[i++] = ft_strdup(*environ++);
	g_env[i++] = NULL;
	ft_signals();
	build_env();
	ft_prompt();
	(void)ac;
	(void)av;
	return (0);
}
