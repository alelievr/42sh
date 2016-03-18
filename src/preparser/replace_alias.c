/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:52:54 by alelievr          #+#    #+#             */
/*   Updated: 2016/03/18 18:58:13 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static char			*cmd_copy_alias_name(char **s, char *buff)
{
	char		*begin;

	begin = buff;
	while (**s && ft_isspace(**s))
		(*s)++;
	if (!*s)
		return (NULL);
	while (**s && !ft_isspace(**s))
		*buff++ = *(*s)++;
	*buff = 0;
	return (begin);
}

char			*cmd_replace_alias(char *s)
{
	static char	buff[0xF0000];
	char		aliasname[0xF00];
	char		*alias;
	char		*begin;
	size_t		i;

	begin = s;
	cmd_copy_alias_name(&s, aliasname);
	printf("aliasname = %s\n", aliasname);
	if ((alias = get_alias_value(aliasname)))
	{
		ft_strcpy(buff, alias);
		i = ft_strlen(alias);
		ft_strcpy(buff + i, s);
		return (buff);
	}
	return (begin);
}
