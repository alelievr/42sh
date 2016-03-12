#include "ft_42sh.h"

void		pr_history_up(t_prompt *d)
{
	(void)d;
}

void		pr_history_dw(t_prompt *d)
{
	(void)d;
}

void		pr_history(t_prompt *d)
{
	if (d->key == PR_UP)
		pr_history_up(d);
	else
		pr_history_dw(d);
}
