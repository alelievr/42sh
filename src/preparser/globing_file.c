/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:37:49 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/24 00:49:29 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/syslimits.h>
#include <sys/stat.h>

static int		cmd_has_wildcard(char *s)
{
	char	*begin;

	begin = s;
	while (*s)
	{
		if (*s == '*' || *s == '?' || *s == '[')
			return (1);
		s++;
	}
	return (0);
}


static void		copy_next_regex(char **s, char *buff, size_t max)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = *s;
	while (ret[i] == '/')
		i++;
	while (ret[i] && ret[i] != '/' && i < max - 1)
		*buff++ = ret[i++];
	*buff = 0;
	*s = ret + i;
}

static char		*concat_path(char *dirs, char *file)
{
	if (!*dirs)
	{
		if (ft_strncmp(file, "./", 2) && ft_strcmp(file, "."))
			strcpy(dirs, "./");
		strlcat(dirs, file, PATH_MAX);
		return (dirs);
	}
	if (dirs[strlen(dirs) - 1] != '/')
		strlcat(dirs, "/", PATH_MAX);
	strlcat(dirs, file, PATH_MAX);
	return (dirs);
}

static t_mlist	*new_mlist(char *s)
{
	t_mlist	*ret;

	if (!(ret = malloc(sizeof(t_mlist))))
		exit(-1);
	if (!(ret->str = malloc(sizeof(char) * PATH_MAX)))
		exit(-1);
	strcpy(ret->str, s);
	ret->next = NULL;
	return (ret);
}

static int		isdir(char *path)
{
	struct stat	st;

	lstat(path, &st);
	return (S_ISDIR(st.st_mode));
}

static void		cmd_create_path_regex(char **s, char *oldpath, char *path, char *regex)
{
	if (!*oldpath && **s != '/' && ft_strncmp(*s, "./", 2))
		strlcpy(path, "./", PATH_MAX);
	else if (!*oldpath && **s == '/' && ft_strncmp(*s, "./", 2))
		strlcpy(path, "/", PATH_MAX);
	else
		strlcpy(path, oldpath, PATH_MAX);
//	printf("fullregex2 = %s\n", *s);
	copy_next_regex(s, regex, 0xF00);
//	printf("oldpath = %s\n", oldpath);
//	printf("regex = %s\n", regex);
//	printf("path = %s\n", path);
	while (!cmd_has_wildcard(regex) && *regex)
	{
		concat_path(path, regex);
//		printf("fullregex2 = %s\n", *s);
		copy_next_regex(s, regex, 0xF00);
//		printf("fullregex2 = %s\n", *s);
//		printf("regex = %s\n", regex);
//		printf("path = %s\n", path);
	}
}

static int		cmd_is_last_regex(char *r)
{
	while (*r && *r != '/' && *r != '*' && *r != '?' && *r != '[')
		r++;
	if (*r == '/')
		while (*r && *r != '*' && *r != '?' && *r != '[')
			r++;
	return (!*r);
}

int             cmd_globing_match(char *s1, char *s2);

static void		cmd_list_add_file_if_matching(char *fname, char *fpath, char *regex, t_mlist **t, char *fullregex)
{
	char			buff[PATH_MAX];
	t_mlist			*new;

	if (*fname == '.' && *regex != '.')
		return ;
	strcpy(buff, fpath);
	concat_path(buff, fname);
	if (cmd_globing_match(fname, regex)) //match files with regex
	{
		if (cmd_is_last_regex(fullregex) || (!cmd_is_last_regex(fullregex) && isdir(buff)))
		{
			new = new_mlist(buff);
			new->next = *t;
			*t = new;
		}
	}
}

static void		cmd_add_list_to_list(t_mlist *t, t_mlist **b, char *end)
{
	t_mlist		*new;
	char		buff[PATH_MAX];

//	printf("end = %s\n", end);
	while (t)
	{
		strlcpy(buff, t->str, PATH_MAX);
		strlcat(buff, end, PATH_MAX);
		if (access(buff, F_OK) == 0)
			GOTO(list_add_matched);
		strlcpy(buff, t->str, PATH_MAX);
		ft_strlcat(buff, "/", PATH_MAX);
		strlcat(buff, end, PATH_MAX);
		if (access(buff, F_OK) == 0)
			GOTO(list_add_matched);
		t = t->next;
		continue ;
		list_add_matched:
	//	printf("final match path = %s\n", buff);
		new = new_mlist(buff);
		new->next = *b;
		*b = new;
		t = t->next;
	}
}

static void		cmd_match_patern_rec(char *s, char *p, t_mlist **b)
{
	char			*regex;
	char			*path;
	t_mlist			*tmp;
	DIR				*dir;
	struct dirent	*dd;

	if (!(regex = malloc(sizeof(char) * 0xF00)))
		exit(-1);
	if (!(path = malloc(sizeof(char) * PATH_MAX)))
		exit(-1);
	cmd_create_path_regex(&s, p, path, regex);

	tmp = NULL;
//	printf("matching regex withs files in dirs: %s\n", regex);
//	printf("fullregex = %s\n", s);
	if (!(dir = opendir(path)))
		return ;
	while ((dd = readdir(dir)))
		cmd_list_add_file_if_matching(dd->d_name, path, regex, &tmp, s);
	closedir(dir);

	///////////////////////////////////////////////////////////////
/*	printf("file list:\n");
	t_mlist	*tt = tmp;
	while (tt)
	{
		printf("\t%s\n", tt->str);
		tt = tt->next;
	}*/
	///////////////////////////////////////////////////////////////

//	printf("fullregex = %s\n", s);
	if (cmd_is_last_regex(s))
		cmd_add_list_to_list(tmp, b, s);
	else
		while (tmp)
		{
			cmd_match_patern_rec(s, tmp->str, b);
			free(tmp->str);
			//TODO: free
			tmp = tmp->next;
		}
	tmp = NULL;
	free(regex);
}

t_mlist			*cmd_match_patern_files(char *s)
{
	t_mlist		*tmp;

	tmp = NULL;
	cmd_match_patern_rec(s, "", &tmp);
	return (tmp);
}
/*
int			main(int ac, char **av)
{
	t_mlist			*tmp;

	if (ac == 2)
	{
		tmp = cmd_match_patern_files(av[1]);
		printf("returned file list:\n");
		while (tmp)
		{
			printf("%s\n", tmp->str);
			tmp = tmp->next;
		}
	}
	return (0);
}*/
