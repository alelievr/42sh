/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_hashtable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:52:22 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/17 19:42:54 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <dirent.h>

t_hashtable				*get_binhash(t_hashtable *h)
{
	static t_hashtable	*ht = NULL;

	if (h)
		ht = h;
	return (ht);
}

char					*get_binhash_path(unsigned long hash)
{
	t_hashtable	*h;

	if (!(h = get_binhash(NULL)))
		return (NULL);
	while (h)
	{
		if (h->hash == hash)
			return (h->path);
		h = h->next;
	}
	return (NULL);
}

static void				add_binhash_bin(char *cur, t_hashtable **ht,
		t_hashtable **begin)
{
	static char     path[0xF000];
	DIR             *dir;
	struct dirent   *dd;

	if ((dir = opendir(cur)))
	{
		while ((dd = readdir(dir)))
		{
			if (*dd->d_name == '.')
				continue ;
			strlcpy(path, cur, sizeof(path));
			strlcat(path, "/", sizeof(path));
			strlcat(path, dd->d_name, sizeof(path));
			if (access(path, F_OK | X_OK) != 0)
				continue ;
			if (add_hashtable_entry(ht,
						new_hashtable_entry(hashstring(dd->d_name), path)))
				*begin = *ht;
			else
				*ht = (*ht)->next;
		}
	}
}

void                    load_binhash(void)
{
	static char buff[0xF0000];
	char        *tmp_path;
	char        *cur;
	char        *ptr;
	t_hashtable	*ht;
	t_hashtable	*begin;

	ht = NULL;
	if (!(tmp_path = get_env("PATH")))
		return ;
	strncpy(buff, tmp_path, sizeof(buff) - 1);
	cur = buff;
	ptr = buff;
	while (*ptr)
	{
		ptr++;
		if (*ptr == ':' || !*ptr)
		{
			*ptr = 0;
			add_binhash_bin(cur, &ht, &begin);
			cur = ptr + 1;
			ptr++;
		}
	}
	get_binhash(begin);
}

void                    delete_binhash(void)
{
	t_hashtable	*ht;
	t_hashtable	*tmp;

	ht = get_binhash(NULL);
	if (ht)
	{
		tmp = ht->next;
		free(ht->path);
		free(ht);
		ht = tmp;
	}
}
