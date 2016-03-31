/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_left_redir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 11:20:57 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/20 14:33:11 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <fcntl.h>

void			ft_double_left_redir_prompt(char **av, int fd)
{
	char		line[0xF000];
	int			ret;

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
		ft_putstr(">> ");
	}
}

void			ft_double_left_redir(int ac, char **av)
{
	int			i;
	int			fd;
	char		*file;

	file = "/tmp/tmpstdin";
	i = 0;
	if ((fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0755)) == -1)
	{
		ft_putstr("broken redirection !\n");
		return ;
	}
	ft_putstr(">> ");
	ft_double_left_redir_prompt(av, fd);
	close(fd);
	ft_left_redir(1, &file);
	(void)ac;
}
