/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:27:16 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/19 19:51:43 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

inline void				ft_dbg(char *file, int line)
{
	char				*f;
	static int			fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_RDWR);
	f = strrchr(file, '/');
	f = (f == NULL ? file : f + 1);
	ft_fprintf(fd, "%{BF}[ %{bF}Debug%{!bF}: %{F}%s%{F}: %{F}%d%{F} ]%{0}\n",
			154, 0, 9, 0, 125, f, 0, 125, line, 0);
}
