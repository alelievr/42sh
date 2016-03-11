/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 14:57:00 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/20 15:01:25 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int			get_stdin(void)
{
	static int		fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_RDWR);
	return (fd);
}
