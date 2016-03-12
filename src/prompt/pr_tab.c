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

static char	**get_autocomplete_list(t_prompt *p, char **beginword, size_t blen)
{
	DIR				*dir;
	struct dirent	*d;
	char			**ret;
	size_t			i;
	char			buff[PATH_MAX + 1];

	if (is_dir(*beginword) && (*beginword)[blen - 1] != '/')
	{
		ft_strcpy(*beginword + blen, "/");
		p->index++;
	}
	//TODO: memory leaks !
	if (!(ret = malloc(sizeof(char *) * 1000)))
		m_error();
	if (ft_strchr(*beginword, '/'))
	{
		ft_strlcpy(buff, *beginword, ft_strrchr(*beginword, '/') - *beginword + 1);
		*beginword += ft_strlen(buff) + 1;
		blen -= ft_strlen(buff) + 1;
	}
	else
		ft_strlcpy(buff, "./", sizeof(buff));
	printf("blen = %li\n", blen);
	printf("buff = [%s]\n", buff);
	printf("new beginword = [%s]\n", *beginword);
	if (!(dir = opendir(buff)))
		return (NULL);
	i = 0;
	while ((d = readdir(dir)))
		if ((!blen && *d->d_name != '.') || (!ft_strncmp(*beginword, d->d_name,
						blen) && blen != ft_strlen(d->d_name)))
			ret[i++] = ft_strdup(d->d_name) + blen;
	closedir(dir);
	return (ret);
}

void		pr_tab(t_prompt *d)
{
	char			*wordptr;
	const size_t	len = ft_strlen(d->buff);
	char			**ac_list;

	printf("current prompt = %s\n", d->buff);
	wordptr = d->buff + len;
	while (wordptr != d->buff && wordptr[-1] != ' ')
		--wordptr;
	printf("curent word = |%s|\n", wordptr);
	ac_list = get_autocomplete_list(d, &wordptr, ft_strlen(wordptr));
	if (!ac_list) {
		printf("an error occured !\n");
		exit(-1);
	}
//	for (int i = 0; ac_list[i]; i++)
//		printf("ac_list = %s\n", *ac_list++);
	if (*ac_list)
	{
		while (**ac_list)
		{
			d->key = **ac_list;
			pr_addchar(d);
			(*ac_list)++;
		}
	}
	else if ((d->key = ' '))
		pr_addchar(d);
}
