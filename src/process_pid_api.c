#include "ft_42sh.h"

pid_t			get_fg_pid(pid_t p)
{
	static pid_t	pid = 0;

	if (p)
		pid = p;
	return (pid);
}

t_list			*get_bg_pid_list(t_list *l)
{
	static t_list	*pid_list = NULL;

	if (l)
		pid_list = l;
	return (pid_list);
}

int				delete_last_bg_pid(void)
{
	t_list			*plist;

	plist = get_bg_pid_list(NULL);
	if (!plist)
		return (0);
	get_bg_pid_list(plist->next);
	free(plist);
	return (1);
}

void			add_bg_pid(pid_t p)
{
	t_list	*plist;
	t_list	*ltmp;

	plist = get_bg_pid_list(NULL);
	ltmp = plist;
	ft_lstadd(&plist, ft_lstnew(0, p));
	if (ltmp != plist)
		get_bg_pid_list(plist);
}

pid_t			get_last_bg_pid(void)
{
	const t_list	*pid_list = get_bg_pid_list(NULL);

	if (!pid_list)
		return (-1);
	return (pid_list->content_size);
}
