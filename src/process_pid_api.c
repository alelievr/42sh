#include "ft_42sh.h"

pid_t			get_foreground_pid(pid_t p)
{
	static pid_t	pid = 0;

	if (p)
		pid = p;
	return (pid);
}

pid_t			get_last_backgrounded_pid(pid_t p)
{
	static t_list	*pid_list = NULL;

	if (!pid_list && p)
		ft_lstadd(&pid_list, ft_lstnew(0, p));
	//TODO finish the function
	return 0;
}
