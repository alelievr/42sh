/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rw_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 22:44:13 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/24 22:56:50 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <fcntl.h>
#include <sys/syslimits.h>
#define HISTORY_SEP_CHAR		'\x80'

void			load_history(t_prompt *d)
{
	int			fd;
	char		path[PATH_MAX + 1];
	char		*home;
	char		*tmp;

	tmp = NULL;
	d->history = NULL;
	if ((home = get_env("HOME")))
	{
		ft_strcpy(path, home);
		ft_strcat(path, "/.42sh_history");
		if ((fd = open(path, O_RDONLY | O_CREAT, 0644)) != -1)
			while (get_next_line_c(fd, &tmp, HISTORY_SEP_CHAR))
			{
				//TODO: opti !!!
				if (!d->history)
					d->history = ft_lstnew(tmp, ft_strlen(tmp) + 1);
				else
					ft_lstback(d->history, ft_lstnew(tmp, ft_strlen(tmp) + 1));
			}
		else
			ft_printf("can't open the file ~/.42sh_history");
	}
	else
		ft_printf("can't find the file ~/.42sh_history");
	get_history_list(d->history);
}

void			write_history(t_prompt *d)
{
	int			fd;
	char		path[PATH_MAX + 1];
	char		*home;
	t_list		*h;

	if ((home = get_env("HOME")))
	{
		ft_strcpy(path, home);
		ft_strcat(path, "/.42sh_history");
		if ((fd = open(path, O_WRONLY | O_CREAT, 0644)) != -1)
		{
			h = d->history;
			while (h)
			{
				write(fd, h->content, h->content_size - 1);
				write(fd, (char[]){HISTORY_SEP_CHAR}, 1);
				h = h->next;
			}
		}
		else
			ft_printf("can't open the file ~/.42sh_history");
	}
	else
		ft_printf("can't find the file ~/.42sh_history");
}
