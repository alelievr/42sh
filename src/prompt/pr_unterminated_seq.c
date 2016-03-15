#include "ft_42sh.h"

int			check_unterminated_sequences(t_prompt *d)
{
	size_t		len;

	len = ft_strlen(d->buff);
	if (d->key == 4 && *(d->buff))
		return (1);
	if (len && d->buff[len - 1] == '\\')
	{
		d->key = '\n';
		pr_addchar(d);
		pr_initline(d);
		return (1);
	}
	return (0);
}
