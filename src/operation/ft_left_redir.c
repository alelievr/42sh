/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 23:37:45 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/20 12:29:39 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <fcntl.h>

void			ft_left_redir(int ac, char **av)
{
	int		i;
	int		fd;

	i = 0;
	while (i < ac)
	{
		if (av[i])
		{
			if ((fd = open(*av, O_RDONLY)) == -1)
				ft_putstr("Can't open file for redirecion left !\n");
			else
			{
				FT_DBG;
				dup2(fd, 0);
				close(0);
			}
		}
		i++;
	}
}
