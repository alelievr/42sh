/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:23:25 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/24 23:08:18 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#define IFBREAK_(x, y)	if (x) { y; break ; }

static int		cmd_is_to_glob(char *s)
{
	char	*begin;
	int		b;
	size_t	i;

	begin = s;
	i = 0;
	b = 0;
	while (s[i])
	{
		if (s[i] == '\'' && (i == 0 || (s[i - 1] != '\\')))
			b = ((b >> 0) & 1) ? b ^ (1 << 0) : b | (1 << 0);
		if (s[i] == '`' && (i == 0 || (s[i - 1] != '\\')))
			b = ((b >> 1) & 1) ? b ^ (1 << 1) : b | (1 << 1);
		if (s[i] == '\"' && (i == 0 || (s[i - 1] != '\\')))
			b = ((b >> 2) & 1) ? b ^ (1 << 2) : b | (1 << 2);
		if (!b && (s[i] == '*' || s[i] == '?' || s[i] == '{'
				|| s[i] == '[' || s[i] == '}' || s[i] == ']'))
			return (1);
		i++;
	}
	return (0);
}

static char		*cmd_globing_expand_string(char *s, char *buff)
{
	static char	tmps[0xF0000];
	size_t	i;
	char	*ret;
	int		b;

	ret = buff;
	ft_strcpy(buff, s);
	while (cmd_is_to_glob(buff))
	{
		ft_strcpy(tmps, buff);
		i = 0;
		b = 0;
		while (tmps[i])
		{
			if (tmps[i] == '\'' && b && (i == 0 || (tmps[i - 1] != '\\')))
				b = ((b >> 0) & 1) ? b ^ (1 << 0) : b | (1 << 0);
			if (tmps[i] == '`' && b && (i == 0 || (tmps[i - 1] != '\\')))
				b = ((b >> 1) & 1) ? b ^ (1 << 1) : b | (1 << 1);
			IFBREAK_((!b && tmps[i] == '{'), cmd_globing_expand_braces(tmps, buff));
			IFBREAK_((!b && (tmps[i] == '*' || tmps[i] == '?' || tmps[i] == '[')),
					cmd_globing_expand_wildcard(tmps, buff));
			i++;
		}
	}
	return (ret);
}

char			*cmd_globing_expand(char *s)
{
	static char		buff[0xF0000];

	//TODO: check the to-glob-expression integrity !!!
	if (cmd_is_to_glob(s))
	{
		printf("to glob string: %s\n", s);
		cmd_globing_expand_string(s, buff);
		free(s);
//		printf("new string: %s\n", buff);
		return (ft_strdup(buff));
	}
	return (s);
}
