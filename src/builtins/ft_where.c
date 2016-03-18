/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_where.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:37:06 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/17 22:43:53 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <sys/syslimits.h>

static void		ft_where_command(char *c)
{
	t_hashtable		*binht;
	t_alias			*al;
	int				matched;
	char			filename[PATH_MAX + 1];

	matched = 0;
	binht = get_binhash(NULL);
	al = get_alias_list(NULL);
	while (al)
	{
		if (!ft_strcmp(c, al->alias) && ((matched = 1)))
			ft_printf("%s: aliased to %s\n", c, al->value);
		al = al->next;
	}
	while (binht)
	{
		get_filename(binht->path, filename);
		if (!ft_strcmp(c, filename) && ((matched = 1)))
			ft_printf("%s\n", binht->path);
		binht = binht->next;
	}
	if (!matched)
		ft_printf("%s not found\n", c);
}

int				ft_where(int ac, char **av)
{
	while (*(++av))
		ft_where_command(*av);
	(void)ac;
	return (1);
}
