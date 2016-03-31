/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:21:56 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/19 19:36:15 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <fcntl.h>

void			ft_right_redir(int n, char **files)
{
	int		fd;

	if (n == 1)
	{
		if ((fd = open(*files, O_CREAT | O_RDWR, 0644)) == -1)
			ft_putstr("Broken redirection !\n");
		else
			dup2(fd, 1);
	}
	else
		ft_putstr("Too many arguments for redirection !\n");
}
