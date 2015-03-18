/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:21:56 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/18 17:03:48 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

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
			if ((filedes[i] = open(*files, O_CREAT O_RDWR, S_IRUSR | S_IWUSR
						| S_IRGRP | S_IROTH)) == -1)
				ft_putstr("Broken redirection !\n");
			fd = dup(1);
			dup2(filedes[i], fd);
			n--;
			i++;
		}
		if ((filedes[i] = open(*files, O_CREAT O_RDWR, S_IRUSR | S_IWUSR
					| S_IRGRP | S_IROTH)) == -1)
			ft_putstr("Broken redirection !\n");
		dup2(filedes[i], fd);
	}
	else if (n == 1)
	{
		if ((fd = open(*files, O_CREAT O_RDWR, S_IRUSR | S_IWUSR
						| S_IRGRP | S_IROTH)) == -1)
			ft_putstr("Broken redirection !\n");
		else
			dup2(fd, 1);
	}
}
