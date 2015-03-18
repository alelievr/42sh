/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:30:07 by alelievr          #+#    #+#             */
/*   Updated: 2015/03/18 15:53:14 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char					*get_command(void)
{
	static char			buff[0xF000];
	int					ret;

	ft_printf("%{F}$> %{!F}", 123);
	ret = read(0, buff, 0xF000);
	buff[ret] = '\0';
	return ((char *)buff);
}
