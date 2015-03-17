/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 21:08:56 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/16 22:48:26 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_builtins	g_builts[6] = {
				{"env", ft_env},
				{"unsetenv", ft_unsetenv},
				{"setenv", ft_setenv},
				{"cd", ft_cd},
				{"exit", ft_exit},
				{"echo", ft_echo}
						};

int			ft_builtins(char **com)
{
	int		i;
	int		ac;
	int		ret;

	ret = 0;
	ac = 0;
	while (com[ac])
		ac++;
	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(*com, g_builts[i].name, ft_strlen(*com)) && ((ret = 1)))
			g_builts[i].fun(ac, com);
		i++;
	}
	return (ret);
}
