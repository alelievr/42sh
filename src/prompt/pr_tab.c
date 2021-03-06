/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:28:48 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/25 18:02:55 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <sys/syslimits.h>
#include "ft_42sh.h"

static inline int	add_missing_slash(char *path, size_t len, size_t *index)
{
	char			unscaped_path[PATH_MAX + 1];

	ft_strcpy(unscaped_path, path);
	if (ft_strstr(path, "\\ "))
		unscape_space(unscaped_path);
	if (is_dir(unscaped_path) && path[len - 1] != '/')
	{
		ft_strcpy(path + len, "/");
		if (index)
			(*index)++;
		return (1);
	}
	return (0);
}

static char			**get_autocomplete_list(t_prompt *p, char *beginword,
		size_t blen)
{
	DIR				*dir;
	struct dirent	*d;
	char			**ret;
	size_t			i;
	char			buff[PATH_MAX + 1];

	(void)p;
//	if (add_missing_slash(*beginword, blen, &(p->index)))
//		++(p->len);
	//TODO: memory leaks !
	if (!(ret = malloc(sizeof(char *) * 1000)))
		m_error();
	if (ft_strchr(beginword, '/'))
	{
		get_dirpath(beginword, buff);
		blen = get_filename_length(beginword);
		beginword += get_dirpath_length(beginword);
	}
	else
		ft_strlcpy(buff, "./", sizeof(buff));
	unscape_space(buff);
	printf("blen = %li\n", blen);
	printf("buff = [%s]\n", buff);
	printf("new beginword = [%s]\n", beginword);

	if (!(dir = opendir(buff)))
		return (NULL);
	i = 0;
	while ((d = readdir(dir)))
		if ((!blen && *d->d_name != '.') || (!ft_strncmp(beginword, d->d_name,
						blen) && blen != ft_strlen(d->d_name)))
			ret[i++] = ft_strdup(d->d_name) + blen;
	ret[i] = NULL;
	closedir(dir);
	return (ret);
}

void				pr_tab(t_prompt *d)
{
	char			*wordptr;
	size_t			len = ft_strlen(d->buff);
	char			**ac_list;

	d->index = ft_strlen(d->buff);
	printf("current prompt = %s\n", d->buff);
	wordptr = d->buff + len;
	while (wordptr != d->buff && (wordptr[-1] != ' ' ||
				(wordptr[-1] == ' ' && wordptr[-2] == '\\')))
		--wordptr;
	printf("curent word = |%s|\n", wordptr);
	ac_list = get_autocomplete_list(d, wordptr, ft_strlen(wordptr));
	if (!ac_list)
	{
		BELL;
		return ;
	}
//	for (int i = 0; ac_list[i]; i++)
//		printf("ac_list = %s\n", *ac_list++);
	if (*ac_list)
	{
		ft_strcat(d->buff, *ac_list);
		d->index = ft_strlen(d->buff);
		len = ft_strlen(d->buff);
	//	pr_addstr(d, *ac_list, ft_strlen(*ac_list));
		printf("wptr = %s\n", wordptr);
	}
	else
		BELL;
	if (add_missing_slash(wordptr, ft_strlen(wordptr), NULL))
		(d->index)++;
	else if (access(wordptr, F_OK) == 0)
		pr_addchar(d, ' ');
}
