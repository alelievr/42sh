#include "ft_42sh.h"
#include <signal.h>

int				ft_fg(int ac, char **av)
{
	t_process		*bgprocess;

	if ((bgprocess = get_last_bg_pid()) == NULL)
		ft_printf("fg: no current job\n");
	else
	{
		delete_last_bg_pid();
		bgprocess = get_fg_pid(0, 0, 0);
		kill(bgprocess->pid, SIGCONT);
		get_fg_pid(bgprocess->pid, bgprocess->name, S_RUNNING);
		wait_process(bgprocess->pid, bgprocess->name);
	}
	(void)ac;
	(void)av;
	return (1);
}

int				ft_bg(int ac, char **av)
{
	t_process		*bgprocess;

	if ((bgprocess = get_last_bg_pid()) == NULL)
		ft_printf("bg: no current job\n");
	else
	{
		kill(bgprocess->pid, SIGCONT);
		ft_printf("%i: continued %s\n", bgprocess->pid, bgprocess->name);
		bgprocess->status = S_RUNNING;
	}
	(void)ac;
	(void)av;
	return (1);
}

static char		*get_verbose_status(int status)
{
	if (status == S_RUNNING)
		return ("running");
	else if (status == S_STOPPED)
		return ("suspended");
	else
		return ("finished");
}

int				ft_jobs(int ac, char **av)
{
	t_process	*p;
	int			i;

	i = 0;
	p = get_last_bg_pid();
	if (!p)
		ft_printf("no background process\n");
	while (p)
	{
		ft_printf("[%i] %i: %s %s\n", i, p->pid,
				get_verbose_status(p->status), p->name);
		p = p->next;
		i++;
	}
	(void)ac;
	(void)av;
	return (1);
}
