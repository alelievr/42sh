/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 23:03:05 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/01 23:07:58 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <fcntl.h>

static int	get_log_fd(void)
{
	static int	lfd = -1;

	if (lfd == -1)
		lfd = open("42sh_log", O_CREAT | O_WRONLY | O_APPEND, 0600);
	return (lfd);
}

int			dlog(char *fmt, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, fmt);
	ret = vdprintf(get_log_fd(), fmt, ap);
	va_end(ap);
	return (ret);
}
