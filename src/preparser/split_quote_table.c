/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:22:55 by alelievr          #+#    #+#             */
/*   Updated: 2016/05/23 21:01:11 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static char		*cmd_quote_strndup(char *ptr, size_t max)
{
	char	*ret;
	char	*str;
	int		delete;
	size_t	i;

	if (!(ret = malloc(sizeof(char) * (max + 1))))
		m_error();
	delete = 0;
	str = ret;
	i = -1;
	while (++i < max)
	{
		if (ptr[i] == '\"' && !delete && (i == 0 || (ptr[i - 1] != '\\')))
			continue ;
		if (ptr[i] == '\'' && (i == 0 || (ptr[i - 1] != '\\')))
			delete = ((delete >> 0) & 1) ? delete ^ (1 << 0) : delete | (1 << 0);
		if (ptr[i] == '`' && (i == 0 || (ptr[i - 1] != '\\')))
			delete = ((delete >> 1) & 1) ? delete ^ (1 << 1) : delete | (1 << 1);
		if ((ptr[i] == ' ' && !delete && i != 0 && ptr[i - 1] == '\\')
				|| (ptr[i] == '\n' && !delete && i != 0 && ptr[i - 1] == '\\'))
			--str;
		*str++ = ptr[i];
	}
	*str = 0;
	return (ret);
}

char			**cmd_split_quote_table(char **ptrs, size_t len)
{
	char	**ret;
	size_t	i;

	if (len == 0)
		return (NULL);
	if (!(ret = malloc(sizeof(char *) * (len + 1))))
		m_error();
	i = (size_t)-1;
	while (++i < len)
		ret[i] = cmd_quote_strndup(ptrs[i * 2], ptrs[i * 2 + 1] - ptrs[i * 2]);
	ret[i] = NULL;
	return (ret);
}
