/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:19:23 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/17 16:35:23 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

unsigned long	hashstring(char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

t_hashtable		*new_hashtable_entry(unsigned long hash, const char *path)
{
	t_hashtable	*ret;

	if (!(ret = malloc(sizeof(t_hashtable))))
		m_error();
	ret->hash = hash;
	ret->path = ft_strdup(path);
	ret->next = NULL;
	return (ret);
}

int				add_hashtable_entry(t_hashtable **ht, t_hashtable *i)
{
	if (!*ht)
	{
		*ht = i;
		return (1);
	}
	else
	{
		(*ht)->next = i;
		return (0);
	}
}
