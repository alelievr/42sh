/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:28:48 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/11 20:18:27 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <sys/syslimits.h>
#include "ft_42sh.h"

static char	**get_autocomplete_list(char *beginword, size_t blen)
{
	DIR				*dir;
	struct dirent	*d;
	char			**ret;
	size_t			i;
	char			buff[PATH_MAX + 1];

	i = 0;
	if (!(ret = malloc(sizeof(char *) * 1000)))
		m_error();
	if (ft_strchr(beginword, '/'))
		ft_strlcpy(buff, beginword, beginword - ft_strrchr(beginword, '/') + 1);
	else
		ft_strlcpy(buff, "./", sizeof(buff));
	if (!(dir = opendir(buff)))
		return (NULL);
	while ((d = readdir(dir)))
		if (!ft_strncmp(beginword, d->d_name, blen))
			ret[i++] = ft_strdup(d->d_name);
	return (ret);
}

void		pr_tab(t_prompt *d)
{
	char			*wordptr;
	const size_t	len = ft_strlen(d->buff);
	char			**ac_list;
	size_t			saved_index;
	size_t			saved_col;
	size_t			wlen;

	printf("current prompt = %s\n", d->buff);
	wordptr = d->buff + len;
	while (wordptr != d->buff && wordptr[-1] != ' ')
		--wordptr;
	if (*wordptr == ' ')
	{
		printf("nothing to complte !\n");
		return ;
	}
	printf("curent word = |%s|\n", wordptr);
	
	wlen = ft_strlen(wordptr);
	ac_list = get_autocomplete_list(wordptr, wlen);
	if (!ac_list) {
		printf("an error occured !\n");
	}
//	for (int i = 0; ac_list[i]; i++)
//		printf("ac_list = %s\n", *ac_list++);
	if (*ac_list)
	{
		saved_index = d->index;
		saved_col = d->col;
		(*ac_list) += wlen;
		while (**ac_list)
		{
			d->key = **ac_list;
			pr_addchar(d);
			(*ac_list)++;
		}
	}
	else
		printf("no matches found !\n");
}
