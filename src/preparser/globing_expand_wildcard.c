/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_expand_wildcard.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:13:31 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/22 03:15:59 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <dirent.h>
#include <sys/syslimits.h>

static void				cmd_copy_base_dir_wildcard(char *s, char *buff)
{
	char	*begin;

	begin = buff;
	while (*s && *s != '*')
		*buff++ = *s++;
	*buff = 0;
	get_dirpath(begin, begin);
	if (!*begin)
		ft_strcpy(buff, "./");
}

static int				cmd_has_wildcard_in_buff(char *s)
{
	char	*begin;

	begin = s;
	while (*s)
	{
		if (NOT_ESCAPED(begin, s, '*')
				|| NOT_ESCAPED(begin, s, '?')
				|| NOT_ESCAPED(begin, s, '['))
			return (1);
		s++;
	}
	return (0);
}

static void				cmd_copy_wildcard_expression(char *s, char *buff)
{
	char	*begin;

	begin = s;
	while (*s)
	{
		if (NOT_ESCAPED(begin, s, '*')
				|| NOT_ESCAPED(begin, s, '?')
				|| NOT_ESCAPED(begin, s, '['))
		{
			while (s != begin && *s != '/')
				s--;
			if (*s == '/')
				s++;
			while (*s != '/' && *s)
				*buff++ = *s++;
			*buff = 0;
		}
		s++;
	}
	return ;
}

static void				cmd_expand_wildcard_buff(char *s, char *buff)
{
	static char			pbuff[PATH_MAX];
	static char			regex[0xF000];
	DIR					*dir;
	struct dirent		*dd;

	cmd_copy_base_dir_wildcard(s, pbuff);
	cmd_copy_wildcard_expression(s, regex);
	printf("base wildcard path: %s\n", pbuff);
	printf("base wildcard regex: %s\n", regex);
	if (!(dir = opendir(pbuff)))
		return ;
	while ((dd = readdir(dir)))
		if (cmd_globing_match(dd->d_name, regex))
		{
			ft_strcat(buff, pbuff);
			if (buff[ft_strlen(buff) - 1] != '/')
				ft_strcat(buff, "/");
			ft_strcat(buff, dd->d_name);
			ft_strcat(buff, " ");
		}
}

void					cmd_globing_expand_wildcard(char *s, char *buff)
{
	static char			tmpb[0xF0000];
	printf("before = %s\n", s);
	ft_strcpy(buff, s);
	while (cmd_has_wildcard_in_buff(buff))
	{
		cmd_expand_wildcard_buff(buff, tmpb);
		ft_strcpy(buff, tmpb);
	}
	(void)s;
	(void)buff;
}
