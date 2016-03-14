#include "ft_42sh.h"
#include <signal.h>

int				ft_fg(int ac, char **av)
{
	pid_t	bgprocess;

	if ((bgprocess = get_last_bg_pid()) == -1)
		ft_printf("fg: no current job\n");
	else
	{
		kill(bgprocess, SIGCONT);
		delete_last_bg_pid();
		wait_process(bgprocess);
	}
	(void)ac;
	(void)av;
	return (1);
}

int				ft_bg(int ac, char **av)
{
	pid_t	bgprocess;

	if ((bgprocess = get_last_bg_pid()) == -1)
		ft_printf("fg: no current job\n");
	else
	{
		kill(bgprocess, SIGCONT);
	}
	(void)ac;
	(void)av;
	return (1);
}
