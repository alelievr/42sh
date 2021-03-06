#include "ft_42sh.h"

t_list		*get_history_list(t_list *h)
{
	static t_list	*history = NULL;

	if (h)
		history = h;
	return (history);
}

t_list		*get_history_search(char *s)
{
	t_list	*tmp;
	size_t	len;

	if ((tmp = get_history_list(NULL)))
		return (NULL);
	len = ft_strlen(s);
	while (tmp)
	{
		if (ft_strncmp(s, (char *)tmp->content, len))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list		*get_history_index(size_t index)
{
	t_list	*tmp;
	size_t	i;

	if (!(tmp = get_history_list(NULL)))
		return (NULL);
	i = 0;
	while (tmp)
	{
		if (i == index)
			return (tmp);
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}
