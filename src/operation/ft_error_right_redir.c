/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_right_redir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 19:43:51 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/19 19:51:21 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <fcntl.h>

void			ft_error_right_redir(int ac, char **av)
{
	int		fd;

	if (ac == 1)
	{
		if ((fd = open(*av, O_CREAT | O_RDWR, 0644)) == -1)
			ft_putstr("Broken redirection !\n");
		else
			dup2(fd, 2);
	}
	else
		ft_putstr("Too many arguments for redirection !\n");
}
