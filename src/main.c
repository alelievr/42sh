/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:55:43 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/17 17:06:56 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <stdlib.h>

char	**g_env;
char	**g_var;

int		main(int ac, char **av, char **environ)
{
	int		i;

	i = 0;
	if (!(g_env = (char **)malloc(sizeof(char *) * MAX_ENV)))
		m_error();
	if (!(g_var = (char **)malloc(sizeof(char *) * MAX_VAR)))
		m_error();
	g_var[0] = NULL;
	i = 0;
	while (*environ && i < MAX_ENV - 1)
		g_env[i++] = ft_strdup(*environ++);
	g_env[i++] = NULL;
	ft_signals();
	build_env();
	load_binhash();
	ft_prompt();
	delete_binhash();
	(void)ac;
	(void)av;
	return (0);
}
