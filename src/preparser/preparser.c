/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:27:22 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/31 00:19:29 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void	preparse_split_add(char *s, char **table, size_t *k)
{
	char		*begin;
	char		*word;

	begin = s;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if (!*s)
			break ;
		word = s;
		if (NOT_ESCAPED(begin, s, '\''))
			while (*s && (NOT_ESCAPED(begin, s, '\'')))
				s++;
		if (NOT_ESCAPED(begin, s, '`'))
			while (*s && (NOT_ESCAPED(begin, s, '`')))
				s++;
		while (*s && (!ft_isspace(*s) || NOT_ESCAPED(begin, s, ' ')
					|| (NOT_ESCAPED(begin, s, '\n'))))
			s++;
		table[(*k)++] = ft_strndup(word, s - word);
		if (*k == MAX_BINARY_ARGUMENTS)
			return ;
	}
}

static char	**preparse_resplit_command(char **t)
{
	static char		*table[MAX_BINARY_ARGUMENTS + 1];
	size_t			i;
	size_t			k;

	k = 0;
	i = (size_t)-1;
	while (t[++i])
	{
		preparse_split_add(t[i], table, &k);
/*		if (!(tmp = ft_strsplit(t[i], " \n\r\f\v")))
			continue ;
		{
			if (k == MAX_BINARY_ARGUMENTS)
				break ;
		}
		free(tmp);*/
		if (k == MAX_BINARY_ARGUMENTS)
			break ;
		free(t[i]);
	}
	free(t);
	table[k] = NULL;
	return (table);
}

char		**preparse_command(char *cmd)
{
	char			**ret;
	int				i;

	if (!(cmd = cmd_replace_alias(cmd)))
		return (NULL);
	if (!(ret = cmd_split_quote(cmd)))
		return (NULL);
	i = -1;
	while (ret[++i])
	{
		if (!(ret[i] = cmd_replace_vars(ret[i])))
			return (NULL);
		if (!(ret[i] = cmd_globing_expand(ret[i])))
			return (NULL);
	}
	ret = preparse_resplit_command(ret);
	return (ret);
}
