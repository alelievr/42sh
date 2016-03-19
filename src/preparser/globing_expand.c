/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:23:25 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/18 20:55:08 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

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
		if (s[i] == '\'' && b && (i == 0 || (s[i - 1] != '\\')))
			b = ((b >> 0) & 1) ? b ^ (1 << 0) : b | (1 << 0);
		if (s[i] == '`' && b && (i == 0 || (s[i - 1] != '\\')))
			b = ((b >> 1) & 1) ? b ^ (1 << 1) : b | (1 << 1);
		if (s[i] == '\"' && b && (i == 0 || (s[i - 1] != '\\')))
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
	size_t	i;
	char	*ret;
	int		b;
//	char	*wptr;

	ret = buff;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' && b && (i == 0 || (s[i - 1] != '\\')))
			b = ((b >> 0) & 1) ? b ^ (1 << 0) : b | (1 << 0);
		if (s[i] == '`' && b && (i == 0 || (s[i - 1] != '\\')))
			b = ((b >> 1) & 1) ? b ^ (1 << 1) : b | (1 << 1);
		if (!b && (s[i] == '*' || s[i] == '?' || s[i] == '{'
				|| s[i] == '[' || s[i] == '}' || s[i] == ']'))
		{
	//		wptr = s + i;
	//		while (!ft_isspace(*wptr) && wprt != s)
	//			wptr--;
	//		globing_expand_current(wptr)
		}
		i++;
	}
	return (ret);
}

char			*cmd_globing_expand(char *s)
{
	static char		buff[0xF0000];

	if (cmd_is_to_glob(s))
	{
		printf("to glob string: %s\n", s);
		cmd_globing_expand_string(s, buff);
		free(s);
		return (ft_strdup(buff));
	}
	return (s);
}
