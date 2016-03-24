#include "ft_42sh.h"
#define GET__	(void *)-1

t_process		*get_fg_pid(pid_t p, char *pname, int status)
{
	static t_process	pr = {0, NULL, 0, NULL};

	if (p != 0)
	{
		pr.pid = p;
		pr.name = pname;
		pr.status = status;
	}
	return (&pr);
}

static t_process	*get_bg_pid_list(t_process *l)
{
	static t_process	*pid_list = NULL;

	if (l != GET__)
		pid_list = l;
	return (pid_list);
}

int				delete_last_bg_pid(void)
{
	t_process		*plist;

	plist = get_bg_pid_list(GET__);
	if (!plist)
		return (0);
	get_bg_pid_list(plist->next);
	if (plist->name)
		free(plist->name);
	free(plist);
	return (1);
}

void			add_bg_pid(pid_t p, char *pname, int status)
{
	t_process	*plist;
	t_process	*llist;

	llist = get_bg_pid_list(GET__);
	if (!(plist = (t_process *)malloc(sizeof(t_process))))
		m_error();
	plist->pid = p;
	plist->name = ft_strdup(pname);
	plist->status = status;
	plist->next = llist;
	get_bg_pid_list(plist);
}

t_process			*get_last_bg_pid(void)
{
	t_process		*pid_list;
	
	pid_list = get_bg_pid_list(GET__);
	if (!pid_list)
		return (NULL);
	return (pid_list);
}
