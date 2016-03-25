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

char		*pr_unscape_buff(char *buff)
{
	char	*readptr;
	char	*ret;

	readptr = buff;
	ret = buff;
	while (*readptr)
	{
		if (*readptr == '\\' && (
					*(readptr + 1) == ' ' ||
					*(readptr + 1) == '\n' ||
					*(readptr + 1) == '\x81' ||
					*(readptr + 1) == '\x81'))
			readptr++;
		*buff++ = *readptr++;
	}
	*buff = 0;
	return (ret);
}
