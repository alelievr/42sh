#include "ft_42sh.h"
#include <fcntl.h>
#include <sys/syslimits.h>

void			load_history(t_prompt *d)
{
	int			fd;
	char		path[PATH_MAX + 1];
	char		*home;
	char		*tmp;

	d->history = NULL;
	if ((home = get_env("HOME")))
	{
		ft_strcpy(path, home);
		ft_strcat(path, "/.42sh_history");
		if ((fd = open(path, O_RDONLY | O_CREAT, 0644)) != -1)
			while (get_next_line(fd, &tmp))
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
				write(fd, "\n", 1);
				h = h->next;
			}
		}
		else
			ft_printf("can't open the file ~/.42sh_history");
	}
	else
		ft_printf("can't find the file ~/.42sh_history");
}
