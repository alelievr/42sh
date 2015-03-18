/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:30:07 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/17 00:25:42 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int		get_command(void)
{
	char	buff[0xF000];
	char	*line;
	char	**com;

	while (42)
	{
		ft_bzero(buff, 0xF000);
		read(0, buff, 0xF000);
		line = ft_strtr(buff, '\n', 0);
		line = ft_strtr(line, '\t', ' ');
		com = ft_strsplit(line, ' ');
		ft_builtins(com);
	}
	return (0);
}
