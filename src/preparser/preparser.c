/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:27:22 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/23 22:31:43 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static char	**preparse_resplit_command(char **t)
{
	static char		*table[MAX_BINARY_ARGUMENTS + 1];
	char			**tmp;
	size_t			i;
	size_t			j;
	size_t			k;

	k = 0;
	i = (size_t)-1;
	while (t[++i])
	{
		if (!(tmp = ft_strsplit(t[i], " \n\r\f\v")))
			continue ;
		j = (size_t)-1;
		while (tmp[++j] && ((table[k++] = tmp[j])))
			if (k == MAX_BINARY_ARGUMENTS)
				break ;
		free(tmp);
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
