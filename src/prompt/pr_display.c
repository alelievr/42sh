/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:34:30 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/16 00:14:35 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void	pr_display(t_prompt *d)
{
	static char		print_buff[0xF0000];
	size_t			plen;
	size_t			i;

	ft_printf("%{F}%s%{!F}", 123, PROMPT42);
	i = -1;
	plen = 0;
	while (d->buff[++i])
	{
		if (d->buff[i] == '\n')
		{
			print_buff[plen++] = '\n';
			print_buff[plen++] = '>';
			print_buff[plen++] = ' ';
		}
		else
			print_buff[plen++] = d->buff[i];
	}
	write(1, print_buff, plen);
}

void	pr_display_line(char *s, int prompt)
{
	static char		print_buff[0xF0000];
	size_t			i;

	i = 0;
	while (*s)
		if (*s == '\n')
			break ;
		else
			print_buff[i++] = *s++;
	print_buff[i] = 0;
	if (prompt == 42)
		ft_printf("%{F}%s%{!F}%s", 123, PROMPT42, print_buff);
	else
		ft_printf("> %s", print_buff);
}
