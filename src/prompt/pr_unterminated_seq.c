#include "ft_42sh.h"

int			check_unterminated_sequences(t_prompt *d)
{
	size_t		len;

	len = ft_strlen(d->buff);
	printf("bufflen = %lu\n    len = %lu\n", len, d->len);
	if (d->key == 4 && *(d->buff))
		return (1);
	if (len && d->buff[len - 1] == '\\')
	{
		d->key = '\n';
		pr_addchar(d);
		return (1);
	}
	return (0);
}
