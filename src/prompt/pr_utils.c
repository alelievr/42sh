#include "ft_42sh.h"

t_prompt	*get_current_prompt(t_prompt *p)
{
	static t_prompt	*prompt = NULL;

	if (p)
		prompt = p;
	return (prompt);
}

void		pr_ctrlc_handler(int s)
{
	t_prompt	*d;

	if ((d = get_current_prompt(NULL)))
	{
		ft_printf("\n");
		get_command_init(d);
		ft_printf("%{F}%s%{!F}", 123, PROMPT42);
	}
	(void)s;
}
