/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:21:56 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/18 22:35:27 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <fcntl.h>

void			ft_right_redir(int n, char **files)
{
	int		fd;
	int		filedes[256];
	int		i;

	if (n > 1)
	{
		i = 0;
		while (n != 1)
		{
			if ((filedes[i] = open(*files, O_CREAT | O_RDWR, 0644)) == -1)
				ft_putstr("Broken redirection !\n");
			fd = dup(1);
			dup2(filedes[i], fd);
			ft_printf("duplicate filedes 1 to %i and duped in %i\n",
					fd, filedes[i]);
			n--;
			i++;
		}
		if ((filedes[i] = open(*files, O_CREAT | O_RDWR, 0644)) == -1)
			ft_putstr("Broken redirection !\n");
		dup2(filedes[i], fd);
		ft_printf("duped filedes %i in %i", fd, filedes[i]);
	}
	else if (n == 1)
	{
		if ((fd = open(*files, O_CREAT | O_RDWR, 0644)) == -1)
			ft_putstr("Broken redirection !\n");
		else
			dup2(fd, 1);
	}
}
