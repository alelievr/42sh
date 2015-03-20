/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_left_redir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 11:20:57 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/20 12:20:13 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <fcntl.h>

void			ft_double_left_redir(int ac, char **av)
{
	char		line[0xF000];
	int			i;
	int			ret;
	int			fd;

	i = 0;
	if ((fd = open("/tmp/tmpstdin", O_RDWR, 0755)) == -1)
	{
		ft_putstr("broken redirection !\n");
		return ;
	}
	while ((ret = read(0, line, 0xF000)) >= 0)
	{
		if (ret == -1)
		{
			ft_putstr("Can't read on stdin !\n");
			return ;
		}
		line[ret - 1] = 0;
		line[ret] = 0;
		if (!ft_strcmp(*av, line))
			break ;
		line[ret - 1] = '\n';
		write(fd, line, ret);
	}
	dup2(fd, 0);
	close(0);
	(void)ac;
}
